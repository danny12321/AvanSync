//
// Created by Danny on 10/01/2021.
//

#ifndef AVANSYNC_SERVERCLIENT_HPP
#define AVANSYNC_SERVERCLIENT_HPP


#include "Server.hpp"

class ServerClient {

public:
    ServerClient(Server &server, asio::ip::tcp::iostream &iostream);

    void Run();

    void Disconnect();

    [[nodiscard]] asio::ip::tcp::iostream &getIOStream() const { return iostream; }

    [[nodiscard]] Server &getServer() const { return server; }

    std::string getLine();

    std::vector<std::string> splitOnChar(const std::string &s, char split);

private:
    void handleRequest(std::string &request);

    std::vector<std::string> parse_request(const std::string &request);

    Server &server;
    asio::ip::tcp::iostream &iostream;

    bool connected = true;

    [[nodiscard]] bool clientDisconnected() const;
};


#endif //AVANSYNC_SERVERCLIENT_HPP
