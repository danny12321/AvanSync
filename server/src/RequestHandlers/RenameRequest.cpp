//
// Created by Danny on 08/01/2021.
//

#include "RenameRequest.hpp"
#include <filesystem>

void RenameRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    if(request.size() != 3) {
        client.getIOStream() << "Expected 2 arguments. \"" + request.at(0) + " <path> <new name>\"" << crlf;
        return;
    }

    const std::string &path = client.getServer().getRootDir() + request.at(1);
    const std::string &newName = client.getServer().getRootDir() + request.at(2);

    if (!std::filesystem::exists(path)) {
        client.getIOStream() << "Error: no such file or directory" << crlf;
        return;
    }

//    TODO: check permissions

//  TODO: maybe keep the folder place
    std::filesystem::rename(path, newName);

    client.getIOStream() << "OK" << crlf;
}
