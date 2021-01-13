//
// Created by Danny on 10/01/2021.
//

#include "DownloadRequest.hpp"
#include <fstream>
#include <filesystem>
#include <numeric>
#include <asio.hpp>
#include <iostream>

void DownloadRequest::handleRequest(Client &client, const std::string &request) {
    auto arguments = client.splitOnChar(request, ' ');
    auto &path = arguments.at(1);

    client.getServer() << "GET" << client.getCRLF();
    client.getServer() << arguments.at(1) << client.getCRLF();

    const auto directories = client.splitOnChar(path, '/');
    std::string directory_path;
    directory_path = std::accumulate(directories.begin(),directories.end() - 1, directory_path);

    // get the first message for the size or error
    auto messages = client.getMessages();

    // if its not a number then it will be a error(s) to log
    if(!is_number(messages.at(0))) {
        for(const auto &message: messages)
            std::cout << message << client.getLF();
        return;
    }

    int file_size = std::stoi(messages.at(0));

    // create directories and file
    std::filesystem::create_directories(std::filesystem::path(client.getRootDir() + directory_path));
    std::ofstream file(client.getRootDir() + path,  std::ios::out|std::ios::binary);

    const int buff_size = 512;
    int bytes_read = 0;

    while (bytes_read < file_size) {
        // the last buffer will not be all the way full
        int read_size =  file_size - bytes_read < buff_size ? file_size - bytes_read : buff_size;
        char buff[buff_size];

        // wait for the bytes to be available
        while (client.getServer().rdbuf()->in_avail() + client.getServer().rdbuf()->available() < read_size) {}

        auto &b = client.getServer().read(buff, read_size);
        bytes_read += b.gcount();
        file.write(buff, b.gcount());
    }
}

bool DownloadRequest::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
