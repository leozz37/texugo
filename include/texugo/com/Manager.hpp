#pragma once
#include <string>
#include <unordered_map>
#include "Connection.hpp"

class Manager {
public:
    Manager(const std::unordered_map<std::string, std::string>&);
    void createConnection(const std::string&, const std::string&);
    const std::unordered_map<std::string, Connection> &getConnectionList() const;

private:
    std::unordered_map<std::string, Connection> m_connectionList;
};