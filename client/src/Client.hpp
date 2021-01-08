//
// Created by Danny on 17-12-2020.
//

#ifndef AVANSYNC_CLIENT_HPP
#define AVANSYNC_CLIENT_HPP


#include <asio/ip/tcp.hpp>

class Client {
public:
    Client();

    void run();

private:
    asio::ip::tcp::iostream server;

    void handleRequest();

    const char* server_address{ "localhost" };
    const char* server_port{ "12345" };
    const char* prompt{ "avansync> " };
    const char* lf{ "\n" };
    const char* crlf{ "\r\n" };
};


#endif //AVANSYNC_CLIENT_HPP
