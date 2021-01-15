//
// Created by Danny on 12/01/2021.
//

#ifndef AVANSYNC_SYNCREQUEST_HPP
#define AVANSYNC_SYNCREQUEST_HPP


#include "RequestHandler.hpp"
#include <filesystem>

class SyncRequest : public RequestHandler {
public:
    void handleRequest(Client &client, const std::string &request) override;

private:
    void handleDirectory(Client &client, const std::string &path);

    void handleFile(Client &client, const std::string &path, const std::filesystem::directory_entry &file,
                    const std::vector<std::string> &serverside_rows);

    void createDirectoryIfNotExists(Client &client, const std::string &path, const std::string &name,
                                    const std::vector<std::string> &serverside_rows);

    bool
    fileIsNewerThanServerFile(Client &client, const std::filesystem::directory_entry &entry, const std::string &row);
};


#endif //AVANSYNC_SYNCREQUEST_HPP
