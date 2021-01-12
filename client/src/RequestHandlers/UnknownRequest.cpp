//
// Created by Danny on 12/01/2021.
//

#include <iostream>
#include "UnknownRequest.hpp"

void UnknownRequest::handleRequest(Client &client, const std::string &request) {
    std::cout << "Dont know " << request << " request" << client.getLF();
}
