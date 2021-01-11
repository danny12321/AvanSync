//
// Created by Danny on 10/01/2021.
//

#include <iostream>
#include <algorithm>
#include "./RequestFactory.hpp"
#include "LogRequest.hpp"
#include "DownloadRequest.hpp"
#include "UploadRequest.hpp"

std::unique_ptr<RequestHandler> RequestFactory::getRequestHandler(const std::vector<std::string> &request) {
    std::string req = request.at(0);
    std::transform(req.begin(), req.end(), req.begin(),
                   [](unsigned char c) { return std::toupper(c); } // correct
    );


    if (req == "GET") return std::make_unique<DownloadRequest>();
    if (req == "PUT") return std::make_unique<UploadRequest>();

    return std::make_unique<LogRequest>();
}