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
    while (!clientDisconnected()) {
        std::cout.flush();
        std::string request = getLine();
        handleRequest(request);
    }
}

void ServerClient::handleRequest(std::string &request) {
    std::cout << "client says: " << request << server.getLF();
    auto arguments = splitOnChar(request, ' ');

    if (!arguments.empty())
        RequestFactory().getRequestHandler(arguments)->handleRequest(*this, arguments);
}

std::vector<std::string> ServerClient::splitOnChar(const std::string &s, char split) const {
    std::vector<std::string> result;
    std::stringstream ss(s); // Turn the string into a stream.
    std::string argument;

    while (getline(ss, argument, split)) {
        result.push_back(argument);
    }

    return std::move(result);
}

void ServerClient::Disconnect() {
    connected = false;
}

std::string ServerClient::getLine() {
    std::string request;
    getline(iostream, request);
    if (request.size() > 1)
        request.erase(request.end() - 1);
    return request;
}

const bool ServerClient::clientDisconnected() const {
    if (!connected) return true;
    return iostream.error().value() != 0;
}
