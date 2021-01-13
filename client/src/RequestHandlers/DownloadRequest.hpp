//
// Created by Danny on 10/01/2021.
//

#ifndef AVANSYNC_DOWNLOADREQUEST_HPP
#define AVANSYNC_DOWNLOADREQUEST_HPP


#include "RequestHandler.hpp"

class DownloadRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

private:
    bool is_number(const std::string &s);
};


#endif //AVANSYNC_DOWNLOADREQUEST_HPP
