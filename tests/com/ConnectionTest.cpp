#include "texugo/com/Connection.hpp"
#include <catch2/catch.hpp>

class ConnectionFixture {
public:
    ConnectionFixture() {
        m_connection = new Connection(m_ioContext, m_port);
    }

protected:
    Connection *m_connection;
    boost::asio::io_context m_ioContext;
    std::string m_name = "AAAAAAA";
    short m_port = 5555;
};

TEST_CASE_METHOD(ConnectionFixture, "GetName") {
    const std::string result = m_connection->getName();
    REQUIRE(result == m_name);
}

TEST_CASE_METHOD(ConnectionFixture, "GetPort") {
    const short result = m_connection->getPort();
    REQUIRE(result == m_port);
}