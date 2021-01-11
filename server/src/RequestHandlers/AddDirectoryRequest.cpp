//
// Created by Danny on 08/01/2021.
//

#include <filesystem>
#include "AddDirectoryRequest.hpp"

void AddDirectoryRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    if (request.size() != 3) {
        client.getIOStream() << "Expected 2 arguments. \""+request.at(0)+" <parent dir> <dir name>\"" << crlf;
        return;
    }

    const std::string &path = client.getServer().getRootDir() + request.at(1);
    const std::string &name = request.at(2);


    if(!std::filesystem::is_directory(path)) {
        client.getIOStream() << "Error: no such directory" << crlf;
        return;
    }

    // TODO: check this
    if((std::filesystem::status(path).permissions() & std::filesystem::perms::owner_write) == std::filesystem::perms::none) {
        client.getIOStream() << "Error: no permission" << crlf;
        return;
    }

    bool success = std::filesystem::create_directories(path + "/" + name);

    if(success) client.getIOStream() << "OK" << crlf;
    else client.getIOStream() << "Something went wrong" << crlf;
}
