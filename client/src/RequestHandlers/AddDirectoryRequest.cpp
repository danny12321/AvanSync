//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "AddDirectoryRequest.hpp"

void AddDirectoryRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');
    if (arguments.size() != 3) {
        std::cout << "Error: expected 2 arguments <parent dir> <dir name>" << client.getLF();
        return;
    }

    const auto &path = arguments.at(1);
    const auto &name = arguments.at(2);

    client.getServer() << "MKDIR" << client.getCRLF();
    client.getServer() << path << client.getCRLF();
    client.getServer() << name << client.getCRLF();

    auto messages = client.getMessages();

    for (const auto &message : messages)
        std::cout << message << client.getLF();
}
