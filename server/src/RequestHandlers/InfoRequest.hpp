//
// Created by Danny on 19-12-2020.
//

#ifndef AVANSYNC_INFOREQUEST_HPP
#define AVANSYNC_INFOREQUEST_HPP


#include "RequestHandler.hpp"

class InfoRequest : public RequestHandler {
public:
    void handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) override;

};


#endif //AVANSYNC_INFOREQUEST_HPP
