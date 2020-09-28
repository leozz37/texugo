#pragma once
#include <string>
#include <boost/asio.hpp>

class SenderConnection
{
public:
    SenderConnection(boost::asio::io_context&, short);
    void writeMessage(const std::string&);

private:
    short                    m_port;
    boost::asio::io_context& m_ioContext;
};