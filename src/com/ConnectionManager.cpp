#include "ReceiverConnection.hpp"
#include "ConnectionManager.hpp"
#include "Logger.hpp"
#include <stdexcept>

void ConnectionManager::createConnections(
    const std::unordered_map<std::string, std::string>& receiverAddresses,
    const std::unordered_map<std::string, std::string>& senderAddresses)
{
    createConnection(receiverAddresses, ConnectionManager::CONNECTION_TYPE::RECEIVER);
    createConnection(senderAddresses, ConnectionManager::CONNECTION_TYPE::SENDER);
}

void ConnectionManager::startConnections()
{
    boost::asio::io_service::work work(m_ioService);
    openReceiverConnections();
    m_ioService.run();
}

void ConnectionManager::createConnection(
    const std::unordered_map<std::string, std::string>& connectionsList,
    CONNECTION_TYPE                                     connectionType)
{
    for (auto& connection : connectionsList)
    {
        const std::string& name = connection.first;
        const short        port = std::stoi(connection.second);

        switch (connectionType)
        {
            case ConnectionManager::CONNECTION_TYPE::RECEIVER:
                m_receiverConnections.insert(
                    { name, std::make_unique<ReceiverConnection>(m_ioService, port) });
                Logger::getInstance().logInfo("Receiver Connection created | " + name + ":"
                                              + std::to_string(port));
                break;
            case ConnectionManager::CONNECTION_TYPE::SENDER:
                m_senderConnections.insert(
                    { name, std::make_unique<SenderConnection>(m_ioService, port) });
                Logger::getInstance().logInfo("Sender Connection created   | " + name + ":"
                                              + std::to_string(port));
                break;
            default:
                Logger::getInstance().logError("CONNECTION DOESN'T HAS A TYPE | " + name + ":"
                                               + std::to_string(port));
        }
    }
}

void ConnectionManager::openReceiverConnections()
{
    for (auto& connection : m_receiverConnections)
    {
        connection.second->doAccept();
    }
}

void ConnectionManager::insertConnectionQueue(const std::string& name, const std::string& message)
{
    // TODO: fix this mess, CNX manager shouldn't send message
    auto& connection = m_senderConnections.find(name)->second;
    connection->writeMessage(message);
}

ConnectionManager& ConnectionManager::getInstance()
{
    static ConnectionManager instance;
    return instance;
}