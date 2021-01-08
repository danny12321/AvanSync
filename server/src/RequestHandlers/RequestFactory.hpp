//
// Created by Danny on 19-12-2020.
//

#ifndef AVANSYNC_REQUESTFACTORY_HPP
#define AVANSYNC_REQUESTFACTORY_HPP


#include <string>
#include "RequestHandler.hpp"

class RequestFactory {
public:
    std::unique_ptr<RequestHandler> getRequestHandler(const std::vector<std::string> &request);
};


#endif //AVANSYNC_REQUESTFACTORY_HPP
