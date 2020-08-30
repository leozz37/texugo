#include <catch2/catch.hpp>
#include "texugo/com/Connection.hpp"

class ConnectionFixture {
public:
    ConnectionFixture() {
        m_connection = new Connection(m_name, m_port);
    }

protected:
    Connection *m_connection;
    const std::string m_name = "AAAAAAA";
    const std::string m_port = "5555";
};

TEST_CASE_METHOD(ConnectionFixture, "GetName") {
    const std::string result = m_connection->getName();
    REQUIRE(result == m_name);
}

TEST_CASE_METHOD(ConnectionFixture, "GetPort") {
    const std::string result = m_connection->getPort();
    REQUIRE(result == m_port);
}

TEST_CASE_METHOD(ConnectionFixture, "InsertQueue") {
    const std::string message = "payload";

    m_connection->insertQueue(message);

    const std::size_t result = m_connection->getMessageQueue().size();
    REQUIRE(result == 1);
}

TEST_CASE_METHOD(ConnectionFixture, "RemoveQueue") {
    const std::string message = "payload";

    m_connection->insertQueue(message);
    m_connection->removeQueue();

    const std::size_t result = m_connection->getMessageQueue().size();
    REQUIRE(result == 0);
}

TEST_CASE_METHOD(ConnectionFixture, "ActivateWatermark") {
    const std::string message = "payload";

    for (int i = 0; i < 21; i++) {
        m_connection->insertQueue(message);
    }

    bool result = m_connection->getWatermark();
    REQUIRE(result == true);
}

TEST_CASE_METHOD(ConnectionFixture, "ActivateAndDeactivateWatermark") {
    const std::string message = "payload";

    for (int i = 0; i < 21; i++) {
        m_connection->insertQueue(message);
    }
    m_connection->removeQueue();

    bool result = m_connection->getWatermark();
    REQUIRE(result == false);
}

TEST_CASE_METHOD(ConnectionFixture, "InsertQueueWatermarkOn") {
    const std::string message = "payload";

    m_connection->setWatermark(true);
    m_connection->insertQueue(message);

    const std::size_t result = m_connection->getMessageQueue().size();
    REQUIRE(result == 01);
}

TEST_CASE_METHOD(ConnectionFixture, "InsertQueueFull") {
    const std::string message = "payload";

    for (int i = 0; i < 21; i++) {
        m_connection->insertQueue(message);
    }

    const std::size_t result = m_connection->getMessageQueue().size();
    REQUIRE(result == 20);
}