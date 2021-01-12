//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_UNKNOWNREQUEST_HPP
#define AVANSYNC_UNKNOWNREQUEST_HPP


#include "RequestHandler.hpp"

class UnknownRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_UNKNOWNREQUEST_HPP
