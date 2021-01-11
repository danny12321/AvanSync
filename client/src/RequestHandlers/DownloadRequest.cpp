//
// Created by Danny on 10/01/2021.
//

#include "DownloadRequest.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <numeric>

void DownloadRequest::handleRequest(Client &client, const std::string &request) {
    client.sendMessage(request);

    const auto path = client.splitOnChar(request, ' ').at(1);
    const auto dir = client.splitOnChar(path, '/');
    std::string directory_path;
    directory_path = std::accumulate(dir.begin(),dir.end() - 1, directory_path);

    auto messages = client.getMessages();
//    auto size = std::stoi(messages.at(0));
//
//    std::cout << "Size of file is: " << size << client.getLF();

    std::vector<char> bytes;
    for (const auto &message : messages) {
        std::string current;

        for(const char c : message) {
            if(c == ' ') {
                bytes.push_back((char) std::stoi(current));
                current = "";
            } else {
                current += c;
            }
        }
    }

    std::filesystem::create_directories(std::filesystem::path(client.getRootDir() + directory_path));
    std::ofstream file(client.getRootDir() + path, std::ios::out|std::ios::binary);
    copy(bytes.cbegin(), bytes.cend(), std::ostream_iterator<char>(file));
}
