#include <gtest/gtest.h>
#include "texugo/com/Manager.hpp"

class ManagerFixture: public testing::Test {
public:
    void SetUp() override;

protected:
    Manager *manager;
};

void ManagerFixture::SetUp() {
    std::unordered_map<std::string, std::string> routingAddresses;
    const std::string port = "5555";
    for (int i = 0; i < 5; i++) {
        const std::string name = std::to_string(i);
        routingAddresses.insert({ name, port });
    }
    manager = new Manager(routingAddresses);
}

TEST_F(ManagerFixture, CreateConnection) {
    const std::string name = "AAAAAAA";
    const std::string port = "5555";

    manager->createConnection(name, port);
    auto key = manager->getConnectionList().find(name);
    bool result = key != manager->getConnectionList().end();

    ASSERT_EQ(result, true);
}

TEST_F(ManagerFixture, FindConnectionDoesntExist) {
    const std::string name = "AAAAAAA";

    auto key = manager->getConnectionList().find(name);
    bool result = key != manager->getConnectionList().end();

    ASSERT_EQ(result, false);
}

TEST_F(ManagerFixture, CreateConnectionNameAlreadyExists) {
    const std::string name = "AAAAAAA";
    const std::string port = "5555";

    manager->createConnection(name, port);

    ASSERT_THROW(manager->createConnection(name, port), std::exception);
}