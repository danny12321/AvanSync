//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "DirRequest.hpp"

void DirRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');
    auto path = arguments.size() > 1 ? arguments.at(1) : "";

    client.getServer() << "DIR" << client.getCRLF();
    client.getServer() << path << client.getCRLF();

    auto messages = client.getMessages();

    for(const auto &message : messages)
        std::cout << message << client.getLF();
}
