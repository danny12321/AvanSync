//
// Created by Danny on 09/01/2021.
//

#include <iostream>
#include <numeric>
#include "UploadRequest.hpp"
#include <fstream>
#include <filesystem>

void UploadRequest::handleRequest(ServerClient &client, const std::vector<std::string> &request) {
    const auto path = client.getServer().getRootDir() + client.getLine();
    const auto file_size = std::stoi(client.getLine());

    const auto directories = client.splitOnChar(path, '/');

    std::string directory_path;
    directory_path = std::accumulate(directories.begin(),directories.end() - 1, directory_path);

    // create directories and file
    std::filesystem::create_directories(std::filesystem::path(directory_path));
    std::ofstream file(path,  std::ios::out|std::ios::binary);

    const int buff_size = 512;
    int bytes_read = 0;

    while (bytes_read < file_size) {
        // the last buffer will not be all the way full
        int read_size =  file_size - bytes_read < buff_size ? file_size - bytes_read : buff_size;
        char buff[buff_size];

        // wait for the bytes to be available
        while (client.getIOStream().rdbuf()->in_avail() + client.getIOStream().rdbuf()->available() < read_size) {}

        auto &b = client.getIOStream().read(buff, read_size);
        bytes_read += b.gcount();
        file.write(buff, b.gcount());
    }
}
