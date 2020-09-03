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
    m_threads.join_all();
}

void Manager::createConnection(const std::string& name, short port) {
    // TODO: add unordered_map
    m_threads.create_thread(
        [ObjectPtr = Connection(m_ioContext, port)] {
            ObjectPtr.start();
        });
}