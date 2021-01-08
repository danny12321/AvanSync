//
// Created by Danny on 19-12-2020.
//

#include <iostream>
#include "UnknownRequest.hpp"

void UnknownRequest::handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) {
    std::cout << "Unknown command " << request.at(0) << std::endl;
    client << request.at(0) << " was not recognized." << crlf;
}
