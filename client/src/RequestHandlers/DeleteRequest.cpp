//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "DeleteRequest.hpp"

void DeleteRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');

    client.getServer() << "DEL" << client.getCRLF();
    client.getServer() << arguments.at(1) << client.getCRLF();

    auto messages = client.getMessages();

    for(const auto &message : messages)
        std::cout << message << client.getLF();
}
