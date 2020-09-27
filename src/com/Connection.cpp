#include "texugo/com/Connection.hpp"
#include "texugo/queue/ProcessQueue.hpp"

using boost::asio::ip::tcp;

// Session Methods
Session::Session(tcp::socket socket) : m_socket(std::move(socket)) { }

void Session::start() {
    doRead();
}

void Session::doRead() {
    auto self(shared_from_this());
    m_socket.async_read_some(boost::asio::buffer(m_data, maxLength),
                            [this, self](boost::system::error_code ec, std::size_t length) {
                                if (!ec) {
                                    ProcessQueue::getInstance().insertQueue(m_data);
                                    doWrite(length);
                                }
                            });
}

void Session::doWrite(std::size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(m_socket, boost::asio::buffer("received", length),
                             [this, self](boost::system::error_code ec, std::size_t) {
                                 if (!ec) {
                                     doRead();
                                 }
                             });
}



// Connection Methods
Connection::Connection(boost::asio::io_context& io_context, short port)
    : m_port(port)
    , m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)) { }


void Connection::doAccept() {
    m_acceptor.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket))->start();
                }
                doAccept();
            });
}

void Connection::insertQueue(const std::string& message) {
    Logger::getInstance().logInfo(std::to_string(m_port) + " | Received message");
    m_messageQueue.push(message);
}
