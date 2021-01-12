//
// Created by Danny on 11/01/2021.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include "UploadRequest.hpp"

void UploadRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');

    // TODO CHECK IF FILE EXIST

    auto path = arguments.at(1);
    client.getServer() << "PUT" << client.getCRLF();
    client.getServer() << path << client.getCRLF();
    client.getServer() << std::filesystem::file_size((client.getRootDir() + path).c_str()) << client.getCRLF();

    std::ifstream is((client.getRootDir() + path).c_str(), std::ios::in | std::ios::binary);

    // Fill out the reply to be sent to the server.
    // Still seems to be a bit slow
    char buf[512];
    while (is.read(buf, sizeof(buf)).gcount() > 0) {
        client.getServer().write(buf, is.gcount());
    }
}
