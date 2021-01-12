//
// Created by Danny on 10/01/2021.
//

#include "DownloadRequest.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <numeric>
#include <asio.hpp>

void DownloadRequest::handleRequest(Client &client, const std::string &request) {
    client.sendMessage(request);

    const auto path = client.splitOnChar(request, ' ').at(1);
    const auto dir = client.splitOnChar(path, '/');
    std::string directory_path;
    directory_path = std::accumulate(dir.begin(),dir.end() - 1, directory_path);

    auto messages = client.getMessages();
    int size = std::stoi(messages.at(0));

    std::filesystem::create_directories(std::filesystem::path(client.getRootDir() + directory_path));
    std::ofstream file(client.getRootDir() + path,  std::ios::out|std::ios::binary);

    int bytes_read = 0;
    const int buff_size = 128;
    std::cout << "Size of file is: " << size << client.getLF();

    while (bytes_read < size) {
        int read_size =  size - bytes_read < buff_size ? size - bytes_read : buff_size;

        while (client.getServer().rdbuf()->in_avail() + client.getServer().rdbuf()->available() < read_size) {
            // wait for the bytes
        }

        char buff[buff_size];
        auto &b = client.getServer().read(buff, read_size);

        if(b.gcount() != read_size) {
            std::cout << "OEF "  << b.gcount() << std::endl;
        }

        bytes_read += b.gcount();

        for (int j = 0; j <read_size; ++j)
            file << buff[j];
    }
}
