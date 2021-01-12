//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_DIRREQUEST_HPP
#define AVANSYNC_DIRREQUEST_HPP


#include "RequestHandler.hpp"

class DirRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_DIRREQUEST_HPP
