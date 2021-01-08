//
// Created by Danny on 19-12-2020.
//

#include <iostream>
#include "Server.hpp"
#include "RequestHandlers/RequestFactory.hpp"

Server::Server() {
//    asio::io_context io_context;
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
    std::cout << "client connected from " << client.socket().local_endpoint() << lf;
    client << "Welcome to AvanSync server 1.0" << crlf;
    for (;;) {
        std::string request;
        getline(client, request);
        handleRequest(client, request);


        if(request == "quit") {
            client << "Bye." << crlf;
            std::cout << "will disconnect from client " << client.socket().local_endpoint() << lf;
            break;
        };
    }
}

void Server::handleRequest(asio::ip::tcp::iostream &client, std::string &request) {
    if(request.size() > 1)
        request.erase(request.end() - 1); // remove '\r'

    std::cout << "client says: " << request << lf;
    auto arguments = parse_request(request);

    if(!arguments.empty())
        RequestFactory().getRequestHandler(arguments)->handleRequest(client, arguments);
}

std::vector<std::string> Server::parse_request(const std::string &request) {
    std::vector<std::string> arguments;
    std::stringstream ss(request); // Turn the string into a stream.
    std::string argument;

    while(getline(ss, argument, ' ')) {
        arguments.push_back(argument);
    }

    return arguments;
}