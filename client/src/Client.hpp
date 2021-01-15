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

    std::vector<std::string> getMessages();

    [[nodiscard]] const std::string &getLF() const { return lf; }

    [[nodiscard]] const std::string &getCRLF() const { return crlf; }

    [[nodiscard]] asio::ip::tcp::iostream &getServer() { return server; }

    [[nodiscard]] const std::string &getRootDir() const { return root_dir; }

    [[nodiscard]] std::vector<std::string> splitOnChar(const std::string &s, char split) const;

    void disconnect();

private:
    asio::ip::tcp::iostream server;

    void handleRequest();

    const std::string server_address{"localhost"};
    const std::string server_port{"12345"};
    const std::string prompt{"avansync> "};
    const std::string root_dir{"./client_dir/"};

    const std::string lf{"\n"};
    const std::string crlf{"\r\n"};

    bool connected = true;

};


#endif //AVANSYNC_CLIENT_HPP
