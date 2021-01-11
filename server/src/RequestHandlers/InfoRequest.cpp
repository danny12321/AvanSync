//
// Created by Danny on 19-12-2020.
//

#include "InfoRequest.hpp"

void InfoRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    client.getIOStream() << "AvanSync server 1.0, copyright (c) 2020 Danny Berkelaar." << crlf;
}
