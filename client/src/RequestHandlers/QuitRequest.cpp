//
// Created by Danny on 12/01/2021.
//

#include "QuitRequest.hpp"

void QuitRequest::handleRequest(Client &client, const std::string &request) {
    client.getServer() << "QUIT" << client.getCRLF();
    client.disconnect();
}
