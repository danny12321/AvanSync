//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_RENAMEREQUEST_HPP
#define AVANSYNC_RENAMEREQUEST_HPP


#include "RequestHandler.hpp"

class RenameRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_RENAMEREQUEST_HPP
