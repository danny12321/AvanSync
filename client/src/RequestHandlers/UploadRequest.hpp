//
// Created by Danny on 11/01/2021.
//

#ifndef AVANSYNC_UPLOADREQUEST_HPP
#define AVANSYNC_UPLOADREQUEST_HPP


#include "RequestHandler.hpp"

class UploadRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

};


#endif //AVANSYNC_UPLOADREQUEST_HPP
