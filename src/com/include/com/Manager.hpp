#pragma once
#include <string>
#include <unordered_map>
#include "com/Connection.hpp"

class Manager {
public:
    Manager(const Manager& other) noexcept = delete;
    Manager(Manager&& other) noexcept = delete;
    Manager& operator=(const Manager& other) noexcept = delete;
    Manager& operator=(Manager&& other) noexcept = delete;

    void createConnections(const std::unordered_map<std::string, std::string>&);
    static Manager& getInstance();

private:
    Manager() noexcept = default;
    std::unordered_map<std::string, Connection> m_connectionList;
};