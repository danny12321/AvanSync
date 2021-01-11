//
// Created by Danny on 10/01/2021.
//

#ifndef AVANSYNC_DOWNLOADREQUEST_HPP
#define AVANSYNC_DOWNLOADREQUEST_HPP


#include "RequestHandler.hpp"

class DownloadRequest : public RequestHandler {
public:
    void handleRequest(ServerClient &client, const std::vector<std::string> &request) override;

};


#endif //AVANSYNC_DOWNLOADREQUEST_HPP
