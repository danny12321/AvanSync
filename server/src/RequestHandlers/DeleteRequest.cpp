//
// Created by Danny on 08/01/2021.
//

#include "DeleteRequest.hpp"
#include <filesystem>

void DeleteRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    if (request.size() != 2) {
        client.getIOStream() << "Expected 1 argument. \"" + request.at(0) + " <path>\"";
        return;
    }

    const std::string &path = client.getServer().getRootDir() + request.at(1);

    if (!std::filesystem::exists(path)) {
        client.getIOStream() << "Error: no such file or directory" << crlf;
        return;
    }

    // TODO: check permissions

    bool success = std::filesystem::remove_all(path);

    if (success) client.getIOStream() << "OK" << crlf;
    else client.getIOStream() << "Something went wrong" << crlf;
}
