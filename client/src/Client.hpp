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

    void sendMessage(const std::string &message);

    std::vector<std::string> getMessages();

    [[nodiscard]] const char *getLF() const { return lf; }

    [[nodiscard]] const char *getCRLF() const { return crlf; }

    [[nodiscard]] const asio::ip::tcp::iostream &getServer() const { return server; }

    [[nodiscard]] const std::string &getRootDir() const { return root_dir; }

    std::vector<std::string> splitOnChar(const std::string &s, char split);

private:
    asio::ip::tcp::iostream server;

    void handleRequest();

    const char *server_address{"localhost"};
    const char *server_port{"12345"};
    const char *prompt{"avansync> "};

    const char *lf{"\n"};
    const char *crlf{"\r\n"};
    const std::string root_dir{"./client_dir/"};

};


#endif //AVANSYNC_CLIENT_HPP
