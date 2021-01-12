//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_DELETEREQUEST_HPP
#define AVANSYNC_DELETEREQUEST_HPP


#include "RequestHandler.hpp"

class DeleteRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_DELETEREQUEST_HPP
