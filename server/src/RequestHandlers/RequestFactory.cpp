//
// Created by Danny on 19-12-2020.
//

#include <algorithm>
#include <asio/ip/tcp.hpp>
#include "RequestFactory.hpp"
#include "InfoRequest.hpp"
#include "DirRequest.hpp"
#include "UnknownRequest.hpp"
#include "QuitRequest.hpp"
#include "AddDirectoryRequest.hpp"
#include "DeleteRequest.hpp"
#include "RenameRequest.hpp"

std::unique_ptr<RequestHandler> RequestFactory::getRequestHandler(const std::vector<std::string> &request) {
    std::string req = request.at(0);
    std::transform(req.begin(), req.end(), req.begin(),
                   [](unsigned char c) { return std::toupper(c); } // correct
    );


    if (req == "INFO") return std::make_unique<InfoRequest>();
    if (req == "DIR") return std::make_unique<DirRequest>();
    if (req == "MKDIR") return std::make_unique<AddDirectoryRequest>();
    if (req == "REN") return std::make_unique<RenameRequest>();
    if (req == "DEL") return std::make_unique<DeleteRequest>();
    if (req == "QUIT") return std::make_unique<QuitRequest>();

    return std::make_unique<UnknownRequest>();
}
