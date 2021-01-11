//
// Created by Danny on 10/01/2021.
//

#ifndef AVANSYNC_LOGREQUEST_HPP
#define AVANSYNC_LOGREQUEST_HPP


#include "RequestHandler.hpp"

class LogRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

public:

};


#endif //AVANSYNC_LOGREQUEST_HPP
