#pragma once
#include "texugo/log/Logger.hpp"
#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

// Session Class
class Session: public std::enable_shared_from_this<Session> {
public:
    explicit Session(tcp::socket socket) : m_socket(std::move(socket)) { }
    void start() {
        doRead();
    }

private:
    void doRead();
    void doWrite(std::size_t);

    tcp::socket m_socket;
    enum { maxLength = 1024 };
    char m_data[maxLength]{};
};

// Server Class
class Server {
public:
    Server(boost::asio::io_context& io_context, short port)
            :  m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)) { }
    void doAccept();

private:
    tcp::acceptor m_acceptor;
};