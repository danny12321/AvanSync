//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_QUITREQUEST_HPP
#define AVANSYNC_QUITREQUEST_HPP


#include "RequestHandler.hpp"

class QuitRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_QUITREQUEST_HPP
