//
// Created by Danny on 07/01/2021.
//

#include <iostream>
#include "QuitRequest.hpp"

void QuitRequest::handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) {
    client << "Bye." << crlf;
    std::cout << "will disconnect from client " << client.socket().local_endpoint() << lf;
    throw "Quit event is not implemented";
}
