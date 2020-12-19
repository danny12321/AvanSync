#include <iostream>
#include "Server.hpp"

int main() {
    try {
        Server server;
        server.run();
    }
    catch (const std::exception& ex) {
        std::cerr << "server: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
