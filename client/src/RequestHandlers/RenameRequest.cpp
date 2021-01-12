//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "RenameRequest.hpp"

void RenameRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');

    client.getServer() << "REN" << client.getCRLF();
    client.getServer() << arguments.at(1) << client.getCRLF();
    client.getServer() << arguments.at(2) << client.getCRLF();

    auto messages = client.getMessages();

    for(const auto &message : messages)
        std::cout << message << client.getLF();
}
