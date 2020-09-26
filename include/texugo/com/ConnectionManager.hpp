#pragma once
#include "Connection.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

class ConnectionManager {
public:
    void openConnections(const std::unordered_map<std::string, std::string>&);

private:
    void createConnection(boost::asio::io_service&, const std::string&, short);
    void startConnections();

    std::unordered_map<std::string, std::unique_ptr<Connection>> m_connectionList;
};