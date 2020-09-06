#include "texugo/com/Connection.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>

Manager::Manager(const std::unordered_map<std::string, std::string>& routingAddresses) {

    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    for (auto& connection : routingAddresses) {
       const std::string name = connection.first;
        short port = std::stoi(connection.second);
        createConnection(io_service, name, port);
    }

    startConnections();
    io_service.run();
}

void Manager::createConnection(boost::asio::io_service& io_service, const std::string& name, short port) {
    Logger::getInstance().logInfo("Connection created | " + name + ":" + std::to_string(port));
    m_connectionList.insert( {name, std::make_unique<Connection>(io_service, port)} );
}

void Manager::startConnections() {
    for (auto& connection : m_connectionList) {
        connection.second->doAccept();
    }
}