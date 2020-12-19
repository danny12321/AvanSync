//
// Created by Danny on 19-12-2020.
//

#ifndef AVANSYNC_SERVER_HPP
#define AVANSYNC_SERVER_HPP


#include <asio/ip/tcp.hpp>

class Server {
public:
    Server();

    [[noreturn]] void run();

private:
    std::unique_ptr<asio::ip::tcp::acceptor> server;
    std::unique_ptr<asio::io_context> io_context;

    const int server_port{ 12345 };
    const char* lf{ "\n" };
    const char* crlf{ "\r\n" };
};


#endif //AVANSYNC_SERVER_HPP
