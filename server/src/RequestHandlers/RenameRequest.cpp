//
// Created by Danny on 08/01/2021.
//

#include "RenameRequest.hpp"
#include <filesystem>

void RenameRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    const auto path = client.getServer().getRootDir() + client.getLine();
    const auto newName = client.getServer().getRootDir() + client.getLine();

    if (!std::filesystem::exists(path)) {
        client.getIOStream() << "Error: no such file or directory" << crlf;
        return;
    }

//    TODO: check permissions

//  TODO: maybe keep the folder place
    std::filesystem::rename(path, newName);

    client.getIOStream() << "OK" << crlf;
}
