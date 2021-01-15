//
// Created by Danny on 08/01/2021.
//

#include <filesystem>
#include "AddDirectoryRequest.hpp"

void AddDirectoryRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    const std::string &path = client.getServer().getRootDir() + client.getLine();
    const std::string &name = client.getLine();

    if (!std::filesystem::is_directory(path)) {
        client.getIOStream() << "Error: no such directory" << crlf;
        return;
    }

    if ((std::filesystem::status(path).permissions() & std::filesystem::perms::owner_write) ==
        std::filesystem::perms::none) {
        client.getIOStream() << "Error: no permission" << crlf;
        return;
    }

    bool success = std::filesystem::create_directories(path + "/" + name);

    if (success) client.getIOStream() << "OK" << crlf;
    else client.getIOStream() << "Something went wrong" << crlf;
}
