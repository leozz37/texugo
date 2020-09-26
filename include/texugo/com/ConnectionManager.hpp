#pragma once
#include "Connection.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

class ConnectionManager {
public:
    ConnectionManager(const ConnectionManager& other) noexcept = delete;
    ConnectionManager(ConnectionManager&& other) noexcept = delete;
    ConnectionManager& operator = (const ConnectionManager& other) noexcept = delete;
    ConnectionManager& operator = (ConnectionManager&& other) noexcept = delete;

    void openConnections(const std::unordered_map<std::string, std::string>&);
    void insertConnectionQueue(const std::string&, const std::string&);
    static ConnectionManager& getInstance();

private:
    ConnectionManager() noexcept = default;

    void createConnection(boost::asio::io_service&, const std::string&, short);
    void startConnections();

    std::unordered_map<std::string, std::unique_ptr<Connection>> m_connectionList;
};