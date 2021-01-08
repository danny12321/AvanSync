//
// Created by Danny on 19-12-2020.
//

#ifndef AVANSYNC_UNKNOWNREQUEST_HPP
#define AVANSYNC_UNKNOWNREQUEST_HPP


#include "RequestHandler.hpp"

class UnknownRequest : public RequestHandler {
public:
    void handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) override;
};

#endif //AVANSYNC_UNKNOWNREQUEST_HPP
