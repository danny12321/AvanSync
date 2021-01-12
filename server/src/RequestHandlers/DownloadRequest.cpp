//
// Created by Danny on 10/01/2021.
//

#include "DownloadRequest.hpp"
#include <filesystem>
#include <fstream>

void DownloadRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    auto path = client.getServer().getRootDir() + client.getLine();

    // TODO CHECK IF FILE EXIST AND PERMISSIONS

    client.getIOStream() << std::filesystem::file_size(path.c_str()) << crlf;

    std::ifstream is(path.c_str(), std::ios::in | std::ios::binary);

    // Fill out the reply to be sent to the client.
    // Still seems to be a bit slow
    char buf[512];
    while (is.read(buf, sizeof(buf)).gcount() > 0) {
        client.getIOStream().write(buf, is.gcount());
    }
}
