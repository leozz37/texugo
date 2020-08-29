#include <catch2/catch.hpp>
#include "texugo/com/Manager.hpp"

class ManagerFixture {
public:
    ManagerFixture() {
        std::unordered_map<std::string, std::string> routingAddresses;
        const std::string port = "5555";
        for (int i = 0; i < 5; i++) {
            const std::string name = std::to_string(i);
            routingAddresses.insert({ name, port });
        }
        manager = new Manager(routingAddresses);
    }

protected:
    Manager *manager;
};

TEST_CASE_METHOD(ManagerFixture, "CreateConnection") {
    const std::string name = "AAAAAAA";
    const std::string port = "5555";

    manager->createConnection(name, port);
    auto key = manager->getConnectionList().find(name);
    bool result = key != manager->getConnectionList().end();

    REQUIRE(result == true);
}

TEST_CASE_METHOD(ManagerFixture, "FindConnectionDoesntExist") {
    const std::string name = "AAAAAAA";

    auto key = manager->getConnectionList().find(name);
    bool result = key != manager->getConnectionList().end();

    REQUIRE(result == false);
}

TEST_CASE_METHOD(ManagerFixture, "CreateConnectionNameAlreadyExists") {
    const std::string name = "AAAAAAA";
    const std::string port = "5555";

    manager->createConnection(name, port);

    REQUIRE_THROWS(manager->createConnection(name, port));
}