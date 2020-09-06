#pragma once
#include "Connection.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

class Manager {
public:
    Manager(const std::unordered_map<std::string, std::string>&, boost::asio::io_context&);
    void createConnection(const std::string&, short);
    void startConnections();

private:
    boost::asio::io_context& m_ioContext;
    boost::thread_group m_threads;
    std::unordered_map<std::string, std::unique_ptr<Connection>> m_connectionList;
};