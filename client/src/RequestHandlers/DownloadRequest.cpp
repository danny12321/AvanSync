//
// Created by Danny on 10/01/2021.
//

#include "DownloadRequest.hpp"
#include <fstream>
#include <filesystem>
#include <numeric>
#include <asio.hpp>

void DownloadRequest::handleRequest(Client &client, const std::string &request) {
    client.sendMessage(request);

    const auto path = client.splitOnChar(request, ' ').at(1);
    const auto directories = client.splitOnChar(path, '/');

    std::string directory_path;
    directory_path = std::accumulate(directories.begin(),directories.end() - 1, directory_path);

    // get the first message for the size
    auto messages = client.getMessages();
    int size = std::stoi(messages.at(0));

    // create directories and file
    std::filesystem::create_directories(std::filesystem::path(client.getRootDir() + directory_path));
    std::ofstream file(client.getRootDir() + path,  std::ios::out|std::ios::binary);

    const int buff_size = 512;
    int bytes_read = 0;

    while (bytes_read < size) {
        // the last buffer will not be all the way full
        int read_size =  size - bytes_read < buff_size ? size - bytes_read : buff_size;
        char buff[buff_size];

        // wait for the bytes to be available
        while (client.getServer().rdbuf()->in_avail() + client.getServer().rdbuf()->available() < read_size) {}

        auto &b = client.getServer().read(buff, read_size);
        bytes_read += b.gcount();
        file.write(buff, b.gcount());
    }
}
