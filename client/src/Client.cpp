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

    asio::socket_base::send_buffer_size option(8);
    server.socket().set_option(option);

    const auto &messages = getMessages();
    for (const auto &message : messages)
        std::cout << message << lf;
}

void Client::run() {
    while (server) {
        handleRequest();
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

void Client::sendMessage(const std::string &message) {
    server << message << crlf;
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

    return result;
}