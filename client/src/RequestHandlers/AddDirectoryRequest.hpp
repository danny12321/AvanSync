//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_ADDDIRECTORYREQUEST_HPP
#define AVANSYNC_ADDDIRECTORYREQUEST_HPP


#include "RequestHandler.hpp"

class AddDirectoryRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_ADDDIRECTORYREQUEST_HPP
