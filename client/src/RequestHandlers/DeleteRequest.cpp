//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "DeleteRequest.hpp"

void DeleteRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');

    if (arguments.size() != 2) {
        std::cout << "Expected 1 argument: DEL <path>" << client.getLF();
        return;
    }

    client.getServer() << "DEL" << client.getCRLF();
    client.getServer() << arguments.at(1) << client.getCRLF();

    auto messages = client.getMessages();

    for (const auto &message : messages)
        std::cout << message << client.getLF();
}
