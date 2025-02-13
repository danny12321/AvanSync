//
// Created by Danny on 19-12-2020.
//

#include <iostream>
#include "DirRequest.hpp"
#include <filesystem>
#include <chrono>
#include <iomanip>

void DirRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    const auto path = client.getServer().getRootDir() + client.getLine();

    if (!std::filesystem::is_directory(path)) {
        client.getIOStream() << "Error: no such directory" << crlf;
        return;
    }

    std::ostringstream response;

    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        response <<
                 getFileChar(entry) << "|" <<
                 entry.path().filename().string() << "|" <<
                 getTime(entry) << "|" <<
                 std::to_string(entry.file_size()) << "|" << crlf;
    }

    if (response.tellp() == 0) client.getIOStream() << crlf;
    else client.getIOStream() << response.str();
}

char DirRequest::getFileChar(const std::filesystem::directory_entry &file) const {
    if (file.is_directory()) return 'D';
    if (file.is_regular_file()) return 'F';

    return '*';
}

std::string DirRequest::getTime(const std::filesystem::directory_entry &file) const {
    std::filesystem::file_time_type file_time = std::filesystem::last_write_time(file);
    auto sctp = file_time - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(sctp) + 3600;

    std::tm *gmt = std::gmtime(&tt);
    std::stringstream buffer;
    buffer << std::put_time(gmt, "%Y-%m-%d %H:%M:%S");
    return buffer.str();
}
