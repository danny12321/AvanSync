//
// Created by Danny on 10/01/2021.
//

#include <iostream>
#include "ServerClient.hpp"
#include "RequestHandlers/RequestFactory.hpp"

ServerClient::ServerClient(Server &server, asio::ip::tcp::iostream &iostream) : server(server), iostream(iostream) {
    std::cout << "Client connected from " << iostream.socket().local_endpoint() << server.getLF();
}

void ServerClient::Run() {
    iostream << "Welcome to AvanSync server 1.0" << server.getCRLF();
    while(connected) {
        std::string request;
        getline(iostream, request);
        handleRequest(request);
    }
}

void ServerClient::handleRequest(std::string &request) {
    if(request.size() > 1)
        request.erase(request.end() - 1); // remove '\r'

    std::cout << "client says: " << request << server.getLF();
    auto arguments = parse_request(request);

    if(!arguments.empty())
        RequestFactory().getRequestHandler(arguments)->handleRequest(*this, arguments);
}

std::vector<std::string> ServerClient::parse_request(const std::string &request) {
    std::vector<std::string> arguments;
    std::stringstream ss(request); // Turn the string into a stream.
    std::string argument;

    while(getline(ss, argument, ' ')) {
        arguments.push_back(argument);
    }

    return arguments;
}

void ServerClient::Disconnect() {
    connected = false;
}
