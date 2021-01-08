//
// Created by Danny on 08/01/2021.
//

#include <filesystem>
#include "AddDirectoryRequest.hpp"

void AddDirectoryRequest::handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) {
    if (request.size() != 3) {
        client << "Expected 2 arguments. \""+request.at(0)+" <parent dir> <dir name>\"" << crlf;
        return;
    }

    const std::string &path = request.at(1);
    const std::string &name = request.at(2);


    if(!std::filesystem::is_directory(path)) {
        client << "Error: no such directory" << crlf;
        return;
    }

    // TODO: check this
    if((std::filesystem::status(path).permissions() & std::filesystem::perms::owner_write) == std::filesystem::perms::none) {
        client << "Error: no permission" << crlf;
        return;
    }

    bool success = std::filesystem::create_directories(path + "/" + name);

    if(success) client << "OK" << crlf;
    else client << "Something went wrong" << crlf;
}
