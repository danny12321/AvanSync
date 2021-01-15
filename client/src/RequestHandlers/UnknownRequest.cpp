//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "UnknownRequest.hpp"

void UnknownRequest::handleRequest(Client &client, const std::string &request) {
    client.getServer() << request << client.getCRLF();

    auto messages = client.getMessages();

    for (const auto &message : messages)
        std::cout << message << client.getLF();
}
