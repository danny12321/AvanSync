//
// Created by Danny on 19-12-2020.
//

#include <iostream>
#include "DirRequest.hpp"
#include <filesystem>

void DirRequest::handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) {
    if (request.size() != 2) {
        client << "Expected 1 argument for the " + request.at(0) + " command. \"" +request.at(0)+" <directory>\"" << crlf;
        return;
    }

    const std::string& path = request.at(1);

    if(!std::filesystem::is_directory(path)) {
        client << "Error: no such directory" << crlf;
        return;
    }

    std::ostringstream response;

    for (const auto & entry : std::filesystem::directory_iterator(path)){
        response << getFileChar(entry) << "|" << entry.path().filename().string() << "|TIJD|" << std::to_string(entry.file_size()) << "|\n" ;
    }

    client << response.str() << crlf;

//    std::cout << "Dir request" << std::endl;
//
//    response += "F|file1.txt|2020-03-05 23:45:18|34107\n";
//    response += "F|file2.txt|2018-10-23 08:05:30|218\n";
//    response += "D|Stuff|2020-11-11 16:25:00|0\n";
//    response += "F|trainingdata.dat|2016-04-01 21:15:53|200\n";
//    response += "*|my_symlink|2020-12-05 12:34:56|0\n";
//
//    client << response << crlf;
}

char DirRequest::getFileChar(const std::filesystem::directory_entry &file) const {
    if(file.is_directory()) return 'D';
    if(file.is_regular_file()) return 'F';

    return '*';
}
