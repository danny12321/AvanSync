//
// Created by Danny on 07/01/2021.
//

#ifndef AVANSYNC_QUITREQUEST_HPP
#define AVANSYNC_QUITREQUEST_HPP


#include "RequestHandler.hpp"

class QuitRequest : public RequestHandler {
public:
    void handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) override;

};


#endif //AVANSYNC_QUITREQUEST_HPP
