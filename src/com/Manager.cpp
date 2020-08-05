#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>

Manager::Manager(const std::unordered_map<std::string, std::string>& routingAddresses) {
    for (auto& connection : routingAddresses) {
        const std::string name = connection.first;
        const std::string port = connection.second;
        createConnection(name, port);
    }
}

void Manager::createConnection(const std::string& name, const std::string& port) {
    auto it = m_connectionList.find(name);
    if (it == m_connectionList.end()) {
        Connection cnx(name, port);
        m_connectionList.insert({ name, cnx });
        // TODO: fix logger constructor
       Logger::getInstance().logInfo("Connection created | NAME: " + name + " - PORT: " + port);
    }
    else {
        throw std::runtime_error("Connection NAME already exists");
    }
}

const std::unordered_map<std::string, Connection> &Manager::getConnectionList() const {
    return m_connectionList;
}
