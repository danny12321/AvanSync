//
// Created by Danny on 19-12-2020.
//

#include <iostream>
#include "Server.hpp"
#include "RequestHandlers/RequestFactory.hpp"

Server::Server() {
    io_context = std::make_unique<asio::io_context>();
    server = std::make_unique<asio::ip::tcp::acceptor>(*io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port));
}

[[noreturn]] void Server::run() {
//    auto server = std::make_unique<asio::ip::tcp::acceptor>(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port));
    for (;;) {
        handleClient();
    }
}

void Server::handleClient() {
    std::cout << "waiting for client to connect\n";
    asio::ip::tcp::iostream client;
    server->accept(client.socket());

    ServerClient(*this, client).Run();
}
