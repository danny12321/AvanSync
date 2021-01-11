//
// Created by Danny on 09/01/2021.
//

#ifndef AVANSYNC_UPLOADREQUEST_HPP
#define AVANSYNC_UPLOADREQUEST_HPP


#include "RequestHandler.hpp"

class UploadRequest : public RequestHandler {
public:
    void handleRequest(ServerClient &client, const std::vector<std::string> &request) override;

};


#endif //AVANSYNC_UPLOADREQUEST_HPP
