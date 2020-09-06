#include "texugo/com/Connection.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>

Manager::Manager(const std::unordered_map<std::string, std::string>& routingAddresses ,
                 boost::asio::io_context& io_context) : m_ioContext(io_context) {

//    for (auto& connection : routingAddresses) {
//       const std::string name = connection.first;
//        short port = std::stoi(connection.second);
//        createConnection(name, port);
//    }

    Connection server(m_ioContext, short(5555));
    server.doAccept();

    m_ioContext.run();
    m_threads.join_all();
}

void Manager::createConnection(const std::string& name, short port) {
    // TODO: add unordered_map

}