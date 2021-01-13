//
// Created by Danny on 19-12-2020.
//

#ifndef AVANSYNC_REQUESTHANDLER_HPP
#define AVANSYNC_REQUESTHANDLER_HPP

#include <string>
#include "../ServerClient.hpp"

class RequestHandler {
public:
    virtual void handleRequest(ServerClient &client, const std::vector<std::string> &request) = 0;

protected:
    const std::string crlf{ "\r\n" };
    const std::string lf{ "\n" };
};

#endif //AVANSYNC_REQUESTHANDLER_HPP
