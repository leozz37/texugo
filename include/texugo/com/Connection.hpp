#pragma once
#include "texugo/log/Logger.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <queue>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// Session Class
class Session: public std::enable_shared_from_this<Session> {
public:
    explicit Session(tcp::socket);
    void start();

private:
    void doRead();
    void doWrite(std::size_t);

    tcp::socket m_socket;
    enum { maxLength = 1024 };
    char m_data[maxLength]{};
};

// Server Class
class Connection {
public:
    Connection(boost::asio::io_context&, short);
    void doAccept();
    void insertQueue(const std::string&);

private:
    const short m_port;
    tcp::acceptor m_acceptor;
    std::queue<std::string> m_messageQueue;
};