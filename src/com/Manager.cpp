#include "texugo/com/Connection.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>

Manager::Manager(const std::unordered_map<std::string, std::string>& routingAddresses ,
                 boost::asio::io_context& io_context) : m_ioContext(io_context) {

    for (auto& connection : routingAddresses) {
       const std::string name = connection.first;
        short port = std::stoi(connection.second);
        createConnection(name, port);
    }

    startConnections();
    m_ioContext.run();
    m_threads.join_all();
}

void Manager::createConnection(const std::string& name, short port) {
    Logger::getInstance().logInfo("Connection created | " + name + ":" + std::to_string(port));
    m_connectionList.insert( {name, std::make_unique<Connection>(m_ioContext, port)} );
}

void Manager::startConnections() {
    for (auto& connection : m_connectionList) {
        connection.second->doAccept();
    }
}