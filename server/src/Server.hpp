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

    [[nodiscard]] const std::string &getRootDir() const { return root_dir; }

    [[nodiscard]] const std::string &getLF() const { return lf; }

    [[nodiscard]] const std::string &getCRLF() const { return crlf; }

private:

    std::unique_ptr<asio::ip::tcp::acceptor> server;
    std::unique_ptr<asio::io_context> io_context;

    const int server_port{12345};
    const std::string lf{"\n"};
    const std::string crlf{"\r\n"};
    const std::string root_dir{"./server_dir/"};

    void handleClient();
};


#endif //AVANSYNC_SERVER_HPP
