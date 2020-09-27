#include "texugo/com/ReceiverConnection.hpp"
#include "texugo/com/ConnectionManager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>

void ConnectionManager::startConnections(const std::unordered_map<std::string, std::string>& receiverAddresses,
                                         const std::unordered_map<std::string, std::string>& senderAddresses) {
    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    createReceiverConnections(receiverAddresses, io_service);
    createSenderConnections(senderAddresses, io_service);

    openReceiverConnections();

    io_service.run();
}

void ConnectionManager::createReceiverConnections(const std::unordered_map<std::string, std::string>& receiverAddresses,
                                                 boost::asio::io_service& io_service) {
    for (auto& connection : receiverAddresses) {
        const std::string name = connection.first;
        short port = std::stoi(connection.second);
        Logger::getInstance().logInfo("Receiver Connection created | " + name + ":" + std::to_string(port));
        m_receiverConnections.insert({name, std::make_unique<ReceiverConnection>(io_service, port)} );
    }
}

void ConnectionManager::createSenderConnections(const std::unordered_map<std::string, std::string>& senderAddresses,
                                               boost::asio::io_service& io_service) {
    for (auto& connection : senderAddresses) {
        const std::string name = connection.first;
        short port = std::stoi(connection.second);
        Logger::getInstance().logInfo("Sender Connection created | " + name + ":" + std::to_string(port));
        m_senderConnections.insert( {name, std::make_unique<SenderConnection>(io_service, port)} );
    }
}

void ConnectionManager::openReceiverConnections() {
    for (auto& connection : m_receiverConnections) {
        connection.second->doAccept();
    }
}

void ConnectionManager::insertConnectionQueue(const std::string& name, const std::string& message) {
    // TODO: fix this mess, CNX manager shouldn't send message
    auto& connection = m_senderConnections.find(name)->second;
    connection->writeMessage(message);
}

ConnectionManager& ConnectionManager::getInstance() {
    static ConnectionManager instance;
    return instance;
}