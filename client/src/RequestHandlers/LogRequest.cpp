//
// Created by Danny on 10/01/2021.
//

#include <iostream>
#include "LogRequest.hpp"

void LogRequest::handleRequest(Client &client, const std::string &request) {
    client.sendMessage(request);
    auto messages = client.getMessages();

    for(const auto &message : messages)
        std::cout << message << client.getLF();
}
