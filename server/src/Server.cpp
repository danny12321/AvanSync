//
// Created by Danny on 19-12-2020.
//

#include <iostream>
#include "Server.hpp"

Server::Server() {
//    asio::io_context io_context;
    io_context = std::make_unique<asio::io_context>();
    server = std::make_unique<asio::ip::tcp::acceptor>(*io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port));
}

[[noreturn]] void Server::run() {
//    auto server = std::make_unique<asio::ip::tcp::acceptor>(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port));
    for (;;) {
        std::cout << "waiting for client to connect\n";
        asio::ip::tcp::iostream client;
        server->accept(client.socket());
        std::cout << "client connected from " << client.socket().local_endpoint() << lf;
        client << "Welcome to AvanSync server 1.0" << crlf;
        for (;;) {
            std::string request;
            getline(client, request);

            if(request.size() > 1) {
                request.erase(request.end() - 1); // remove '\r'
            }

            std::cout << "client says: " << request << lf;

            if (request == "quit") {
                client << "Bye." << crlf;
                std::cout << "will disconnect from client " << client.socket().local_endpoint() << lf;
                break;
            }
            else {
                client << request << crlf; // simply echo the request
            }
        }
    }
}
