#pragma once
#include "texugo/com/ReceiverConnection.hpp"
#include "texugo/com/SenderConnection.hpp"
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

    void createConnections(const std::unordered_map<std::string, std::string> &receiverAddresses,
                           const std::unordered_map<std::string, std::string> &senderAddresses);
    void startConnections();
    void insertConnectionQueue(const std::string&, const std::string&);

    static ConnectionManager& getInstance();

private:
    ConnectionManager() noexcept = default;

    enum CONNECTION_TYPE { RECEIVER, SENDER };

    void createReceiverConnections(const std::unordered_map<std::string, std::string>&);
    void createSenderConnections(const std::unordered_map<std::string, std::string>&);

    void createConnection(const std::unordered_map<std::string, std::string>&, CONNECTION_TYPE);
    void openReceiverConnections();

    boost::asio::io_service m_ioService;


    inline static std::unordered_map<std::string, std::unique_ptr<ReceiverConnection>> m_receiverConnections;
    inline static std::unordered_map<std::string, std::unique_ptr<SenderConnection>> m_senderConnections;
};