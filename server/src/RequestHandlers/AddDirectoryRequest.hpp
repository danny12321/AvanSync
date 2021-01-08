//
// Created by Danny on 08/01/2021.
//

#ifndef AVANSYNC_ADDDIRECTORYREQUEST_HPP
#define AVANSYNC_ADDDIRECTORYREQUEST_HPP


#include "RequestHandler.hpp"

class AddDirectoryRequest : public RequestHandler {
public:
    void handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) override;

};


#endif //AVANSYNC_ADDDIRECTORYREQUEST_HPP
