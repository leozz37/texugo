#pragma once
#include "texugo/log/Logger.hpp"
#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <queue>

using boost::asio::ip::tcp;

// Session Class
class Session : public std::enable_shared_from_this<Session>
{
public:
    explicit Session(tcp::socket, short);
    void start();

private:
    void doRead();
    void doWrite(const std::string&);

    tcp::socket m_socket;
    enum
    {
        maxLength = 1024
    };
    char  m_payload[maxLength]{};
    short m_port;
};

// Server Class
class ReceiverConnection
{
public:
    ReceiverConnection(boost::asio::io_context&, short);
    void doAccept();

private:
    const short              m_port;
    tcp::acceptor            m_acceptor;
    boost::asio::io_context& m_ioContext;
};