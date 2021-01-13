//
// Created by Danny on 10/01/2021.
//

#include <iostream>
#include <algorithm>
#include "./RequestFactory.hpp"
#include "DownloadRequest.hpp"
#include "UploadRequest.hpp"
#include "DirRequest.hpp"
#include "RenameRequest.hpp"
#include "DeleteRequest.hpp"
#include "AddDirectoryRequest.hpp"
#include "UnknownRequest.hpp"
#include "QuitRequest.hpp"
#include "SyncRequest.hpp"

std::unique_ptr<RequestHandler> RequestFactory::getRequestHandler(const std::vector<std::string> &request) {
    std::string req = request.at(0);
    std::transform(req.begin(), req.end(), req.begin(),
                   [](unsigned char c) { return std::toupper(c); }
    );

    if (req == "GET") return std::make_unique<DownloadRequest>();
    if (req == "PUT") return std::make_unique<UploadRequest>();
    if (req == "DIR") return std::make_unique<DirRequest>();
    if (req == "REN") return std::make_unique<RenameRequest>();
    if (req == "DEL") return std::make_unique<DeleteRequest>();
    if (req == "MKDIR") return std::make_unique<AddDirectoryRequest>();
    if (req == "QUIT") return std::make_unique<QuitRequest>();
    if (req == "SYNC") return std::make_unique<SyncRequest>();

    return std::make_unique<UnknownRequest>();
}