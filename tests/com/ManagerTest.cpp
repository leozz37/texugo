#include "texugo/com/Manager.hpp"
#include <catch2/catch.hpp>
#include <boost/asio.hpp>

class ManagerFixture {
public:
    ManagerFixture() {
        std::unordered_map<std::string, std::string> routingAddresses;
        const std::string port = "5555";
        for (int i = 0; i < 5; i++) {
            const std::string name = std::to_string(i);
            routingAddresses.insert({ name, port });
        }
        manager = new Manager(routingAddresses, m_ioStream);
    }

protected:
    Manager *manager;
    boost::asio::io_context m_ioStream;
};

//TEST_CASE_METHOD(ManagerFixture, "CreateConnectionNameAlreadyExists") {
//    const std::string name = "AAAAAAA";
//    short port = 5555;
//
//    manager->createConnection(name, port);
//
//    REQUIRE_THROWS(manager->createConnection(name, port));
//}