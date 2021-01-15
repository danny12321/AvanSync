//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "SyncRequest.hpp"
#include "UploadRequest.hpp"
#include "AddDirectoryRequest.hpp"

void SyncRequest::handleRequest(Client &client, const std::string &request) {
    handleDirectory(client, "./");
}

void SyncRequest::handleDirectory(Client &client, const std::string &path) {
    client.getServer() << "DIR " << client.getCRLF();
    client.getServer() << path << client.getCRLF();
    auto serverside_rows = client.getMessages();

    // retrieves a empty string when the directory is empty
    if (serverside_rows.at(0).empty()) serverside_rows.clear();

    for (const auto &entry : std::filesystem::directory_iterator(client.getRootDir() + path)) {
        if (entry.is_directory()) {
            createDirectoryIfNotExists(client, path, entry.path().filename().string(), serverside_rows);
            handleDirectory(client, path + "/" + entry.path().filename().string());
        } else {
            handleFile(client, path, entry, serverside_rows);
        }
    }
}

void SyncRequest::handleFile(Client &client, const std::string &path, const std::filesystem::directory_entry &file,
                             const std::vector<std::string> &serverside_rows) {
    auto filename = file.path().filename().string();
    auto row = std::find_if(serverside_rows.begin(), serverside_rows.end(), [&](const auto &r) {
        return r[0] == 'F' && filename == client.splitOnChar(r, '|').at(1);
    });

    if (row == serverside_rows.end() ||
        fileIsNewerThanServerFile(client, file, serverside_rows[std::distance(serverside_rows.begin(), row)])) {
        std::cout << "New file for server " << path << "/" << filename << std::endl;
        UploadRequest().handleRequest(client, "PUT " + path + "/" + filename);
    }
}

void SyncRequest::createDirectoryIfNotExists(Client &client, const std::string &path, const std::string &name,
                                             const std::vector<std::string> &serverside_rows) {
    auto row = std::find_if(serverside_rows.begin(), serverside_rows.end(), [&](const auto &r) {
        return r[0] == 'D' && name == client.splitOnChar(r, '|').at(1);
    });

    if (row == serverside_rows.end()) {
        std::cout << "Add dir to server " << name << std::endl;
        AddDirectoryRequest().handleRequest(client, "MKDIR " + path + " " + name);
    }
}

bool SyncRequest::fileIsNewerThanServerFile(Client &client, const std::filesystem::directory_entry &entry,
                                            const std::string &row) {
    auto stringTime = client.splitOnChar(row, '|').at(2);
    std::tm t{};
    std::istringstream ss(stringTime);

    ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        return false;
    }

    auto client_file_time = std::filesystem::last_write_time(entry);
    auto sctp = client_file_time - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(sctp);
    auto bb = mktime(&t);

    if (tt > bb) {
        return true;
    }

    return false;
}
