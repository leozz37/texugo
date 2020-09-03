#pragma once
#include "Connection.hpp"
#include <string>
#include <unordered_map>
#include <boost/asio.hpp>

class Manager {
public:
    Manager(const std::unordered_map<std::string, std::string>&, boost::asio::io_context&);
    void createConnection(const std::string&, const std::string&);
    const std::unordered_map<std::string, Connection> &getConnectionList() const;

private:
    std::unordered_map<std::string, Connection> m_connectionList;
};