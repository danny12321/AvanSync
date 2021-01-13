//
// Created by Danny on 17-12-2020.
//

#include "Client.hpp"
#include "RequestHandlers/RequestFactory.hpp"
#include <iostream>

Client::Client() {
    std::cout << "client starting" << std::endl;
    server = asio::ip::tcp::iostream{server_address, server_port};
    if (!server) throw std::runtime_error("could not connect to server");

    const auto &messages = getMessages();
    for (const auto &message : messages)
        std::cout << message << lf;
}

void Client::run() {
    while (server && connected) {
        try {
            handleRequest();
        } catch (const std::exception &e) {
            std::cerr << "Something went wrong in the request: " << e.what() << lf;
        }
    }
}

void Client::handleRequest() {
    std::cout << prompt;
    std::string req;
    if (getline(std::cin, req)) {
        auto request_handler = RequestFactory().getRequestHandler(splitOnChar(req, ' '));
        request_handler->handleRequest(*this, req);
    }
}

std::vector<std::string> Client::getMessages() {
    std::vector<std::string> lines;

    for (std::string line; std::getline(server, line).good();) {
        line.erase(line.end() - 1); // remove '\r'
        lines.push_back(line);

        if (server.rdbuf()->in_avail() == 0)
            break;
    }

    return lines;
}

std::vector<std::string> Client::splitOnChar(const std::string &s, char split) {
    std::vector<std::string> result;
    std::stringstream ss(s); // Turn the string into a stream.
    std::string argument;

    while (getline(ss, argument, split)) {
        result.push_back(argument);
    }

    return std::move(result);
}

void Client::disconnect() {
    connected = false;
}
