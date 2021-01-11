//
// Created by Danny on 10/01/2021.
//

#ifndef AVANSYNC_REQUESTFACTORY_HPP
#define AVANSYNC_REQUESTFACTORY_HPP


#include "./RequestHandler.hpp"

class RequestFactory {
public:
    std::unique_ptr<RequestHandler> getRequestHandler(const std::vector<std::string> &request);

};


#endif //AVANSYNC_REQUESTFACTORY_HPP
