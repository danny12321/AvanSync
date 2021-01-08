//
// Created by Danny on 17-12-2020.
//

#include "Client.hpp"
#include <iostream>

Client::Client() {
    std::cout << "client starting" << std::endl;
    server = asio::ip::tcp::iostream{server_address, server_port};
    if (!server) throw std::runtime_error("could not connect to server");
}

void Client::run() {
    while (server) {
        handleRequest();
    }
}

void Client::handleRequest() {
    for(std::string line; std::getline(server, line).good();) {
        line.erase(line.end() - 1); // remove '\r'
        std::cout << line << std::endl;

        if(server.rdbuf()->in_avail() == 0)
            break;
    }

    std::cout << prompt;
    std::string req;
    if (getline(std::cin, req)) {
        server << req << crlf;
    }


//    if (getline(server, resp)) {
//        resp.erase(resp.end() - 1); // remove '\r'
//        std::cout << resp << lf;
//        if (resp == "Bye.") server.close();
//
//        std::cout << prompt;
//        std::string req;
//        if (getline(std::cin, req)) {
//            server << req << crlf;
//        }
//    }
}
