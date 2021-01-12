//
// Created by Danny on 08/01/2021.
//

#include "DeleteRequest.hpp"
#include <filesystem>

void DeleteRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    const auto path = client.getServer().getRootDir() + client.getLine();

    if (!std::filesystem::exists(path)) {
        client.getIOStream() << "Error: no such file or directory" << crlf;
        return;
    }

    // TODO: check permissions

    bool success = std::filesystem::remove_all(path);

    if (success) client.getIOStream() << "OK" << crlf;
    else client.getIOStream() << "Something went wrong" << crlf;
}
