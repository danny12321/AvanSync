//
// Created by Danny on 10/01/2021.
//

#include "DownloadRequest.hpp"
#include <filesystem>
#include <fstream>

void DownloadRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    if(request.size() != 2) {
        client.getIOStream() << "Expected 1 arguments. \"" + request.at(0) + " <path>\"" << crlf;
        return;
    }

    // TODO CHEKC IF FILE EXIST AND PERMISSIONS

    const auto& path = client.getServer().getRootDir() + request.at(1);
//    client.getIOStream() << std::filesystem::file_size(path.c_str()) << crlf;

    std::ifstream is(path.c_str(), std::ios::in | std::ios::binary);
    if (!is)
    {
        client.getIOStream() << crlf;
        return;
    }

    // Fill out the reply to be sent to the client.
    char buf[4096];
    while (is.read(buf, sizeof(buf)).gcount() > 0) {
    std::string content;
        for (int i = 0; i < is.gcount(); ++i) {
            content.append(std::to_string((int) buf[i])+" ");
        }
        client.getIOStream() << content;
    }

    client.getIOStream() << crlf;
}
