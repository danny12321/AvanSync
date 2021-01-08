//
// Created by Danny on 19-12-2020.
//

#ifndef AVANSYNC_DIRREQUEST_HPP
#define AVANSYNC_DIRREQUEST_HPP


#include <filesystem>
#include "RequestHandler.hpp"

class DirRequest : public RequestHandler {
public:
    void handleRequest(asio::ip::tcp::iostream &client, const std::vector<std::string> &request) override;

private:
    [[nodiscard]] char getFileChar(const std::filesystem::directory_entry &file) const;
    [[nodiscard]] std::string getTime(const std::filesystem::directory_entry &file) const;
};


#endif //AVANSYNC_DIRREQUEST_HPP
