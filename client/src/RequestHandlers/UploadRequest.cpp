//
// Created by Danny on 11/01/2021.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <numeric>
#include "UploadRequest.hpp"

void UploadRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');
    if(arguments.size() < 2) {
        std::cout << "Error expected 1 argument: PUT <path>" << client.getLF();
        return;
    }

    std::string path;
    path = std::accumulate(arguments.begin() + 1, arguments.end(), std::string(),
                           [](const std::string &ss, const std::string &s)
                           {
                               return ss.empty() ? s : ss + " " + s;
                           });

    if (!std::filesystem::exists(client.getRootDir() + path)) {
        std::cout << "Error: no such file or directory" << client.getLF();
        return;
    }

    client.getServer() << "PUT" << client.getCRLF();
    client.getServer() << path << client.getCRLF();
    client.getServer() << std::filesystem::file_size((client.getRootDir() + path).c_str()) << client.getCRLF();

    std::ifstream is((client.getRootDir() + path).c_str(), std::ios::in | std::ios::binary);

    // Fill out the reply to be sent to the server.
    char buf[512];
    while (is.read(buf, sizeof(buf)).gcount() > 0) {
        client.getServer().write(buf, is.gcount());
    }

    auto messages = client.getMessages();
    for(const auto &message : messages)
        std::cout << message << client.getLF();
}
