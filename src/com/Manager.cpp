#include <texugo/com/Manager.hpp>
#include <texugo/log/Logger.hpp>

void Manager::createConnections(const std::unordered_map<std::string, std::string>& routingAddresses) {
    for (auto& connection : routingAddresses) {
        const std::string name = connection.first;
        const std::string port = connection.second;

        Connection cnx(name, port);
        m_connectionList.insert({ name, cnx });
        Logger::getInstance().logInfo("Connection created | NAME: " + name + " - PORT: " + port);
    }
}

Manager& Manager::getInstance() {
    static Manager instance;
    return instance;
}