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
        std::string resp;
        if (getline(server, resp)) {
            resp.erase(resp.end() - 1); // remove '\r'
            std::cout << resp << lf;
            if (resp == "Bye.") break;

            std::cout << prompt;
            std::string req;
            if (getline(std::cin, req)) {
                server << req << crlf;
            }
        }
    }
}