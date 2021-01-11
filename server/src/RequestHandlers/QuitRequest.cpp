//
// Created by Danny on 07/01/2021.
//

#include <iostream>
#include "QuitRequest.hpp"

void QuitRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    client.getIOStream() << "Bye." << crlf;
    std::cout << "will disconnect from client " << client.getIOStream().socket().local_endpoint() << lf;
    client.Disconnect();
}
