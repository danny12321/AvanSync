//
// Created by Danny on 10/01/2021.
//

#ifndef AVANSYNC_REQUESTHANDLER_HPP
#define AVANSYNC_REQUESTHANDLER_HPP


#include "../Client.hpp"

class RequestHandler {
public:
    virtual void handleRequest(Client &client, const std::string &request) = 0;

};


#endif //AVANSYNC_REQUESTHANDLER_HPP
