#include <iostream>
#include <stdexcept>
#include <asio.hpp>
#include "Client.hpp"

int main() {
    try {
        Client client;
        client.run();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
