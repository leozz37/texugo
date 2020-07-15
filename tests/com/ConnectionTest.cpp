#include <gtest/gtest.h>
#include "texugo/com/Connection.hpp"

class ConnectionFixture: public testing::Test {
public:
    void SetUp() override;

protected:
    Connection *m_connection;
    const std::string m_name = "AAAAAAA";
    const std::string m_port = "5555";
};

void ConnectionFixture::SetUp() {
    m_connection = new Connection(m_name, m_port);
}

TEST_F(ConnectionFixture, GetName) {
    const std::string result = m_connection->getName();
    ASSERT_EQ(result, m_name);
}

TEST_F(ConnectionFixture, GetPort) {
    const std::string result = m_connection->getPort();
    ASSERT_EQ(result, m_port);
}

TEST_F(ConnectionFixture, InsertQueue) {
    const std::string message = "payload";

    m_connection->insertQueue(message);

    const std::size_t result = m_connection->getMessageQueue().size();
    ASSERT_EQ(result, 1);
}

TEST_F(ConnectionFixture, RemoveQueue) {
    const std::string message = "payload";

    m_connection->insertQueue(message);
    m_connection->removeQueue();

    const std::size_t result = m_connection->getMessageQueue().size();
    ASSERT_EQ(result, 0);
}

TEST_F(ConnectionFixture, ActivateWatermark) {
    const std::string message = "payload";

    for (int i = 0; i < 21; i++) {
        m_connection->insertQueue(message);
    }

    bool result = m_connection->getWatermark();
    ASSERT_EQ(result, true);
}

TEST_F(ConnectionFixture, ActivateAndDeactivateWatermark) {
    const std::string message = "payload";

    for (int i = 0; i < 21; i++) {
        m_connection->insertQueue(message);
    }
    m_connection->removeQueue();

    bool result = m_connection->getWatermark();
    ASSERT_EQ(result, false);
}

TEST_F(ConnectionFixture, InsertQueueWatermarkOn) {
    const std::string message = "payload";

    m_connection->setWatermark(true);
    m_connection->insertQueue(message);

    const std::size_t result = m_connection->getMessageQueue().size();
    ASSERT_EQ(result, 01);
}

TEST_F(ConnectionFixture, InsertQueueFull) {
    const std::string message = "payload";

    for (int i = 0; i < 21; i++) {
        m_connection->insertQueue(message);
    }

    const std::size_t result = m_connection->getMessageQueue().size();
    ASSERT_EQ(result, 20);
}