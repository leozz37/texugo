#include "texugo/com/Connection.hpp"
#include "texugo/com/ConnectionManager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>


void ConnectionManager::openConnections(const std::unordered_map<std::string, std::string>& routingAddresses) {
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

void ConnectionManager::createConnection(boost::asio::io_service& io_service, const std::string& name, short port) {
    Logger::getInstance().logInfo("Connection created | " + name + ":" + std::to_string(port));
    m_connectionList.insert( {name, std::make_unique<Connection>(io_service, port)} );
}

void ConnectionManager::startConnections() {
    for (auto& connection : m_connectionList) {
        connection.second->doAccept();
    }
}

void ConnectionManager::insertConnectionQueue(const std::string& connection, const std::string& message) {
    // TODO: fix this mess, CNX manager shouldn't send messages
    auto& cnx = m_connectionList.find(connection)->second;
    cnx->writeMessage(message);
}

ConnectionManager& ConnectionManager::getInstance() {
    static ConnectionManager instance;
    return instance;
}