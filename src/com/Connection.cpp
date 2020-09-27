#include "texugo/com/Connection.hpp"
#include "texugo/queue/ProcessQueue.hpp"

using boost::asio::ip::tcp;

// Session Methods
Session::Session(tcp::socket socket, short port)
    : m_socket(std::move(socket))
    , m_port(port) { }

void Session::start() {
    doRead();
}

void Session::doRead() {
    try {
        auto self(shared_from_this());
        m_socket.async_read_some(boost::asio::buffer(m_data, maxLength),
                                 [this, self](boost::system::error_code ec, std::size_t length) {
                                     if (!ec) {
                                         Logger::getInstance().logInfo(std::to_string(m_port) + " | Received message");
                                         ProcessQueue::getInstance().insertQueue(m_data);
                                         doWrite("Received");
                                     }
                                 });
    }
    catch (std::exception& e) {
        Logger::getInstance().logError(e);
    }
}

void Session::doWrite(const std::string& message) {
    try {
        auto self(shared_from_this());
        std::size_t messageLength = message.size();

        boost::asio::async_write(m_socket, boost::asio::buffer(message, messageLength),
                                 [this, self](boost::system::error_code ec, std::size_t) {
                                     if (!ec) {
                                         doRead();
                                     }
                                 });
    }
    catch (std::exception& e) {
        Logger::getInstance().logError(e);
    }
}

// Connection Methods
Connection::Connection(boost::asio::io_context& io_context, short port)
    : m_port(port)
    , m_ioContext(io_context)
    , m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)) { }


void Connection::doAccept() {
    m_acceptor.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket), m_port)->start();
                }
                doAccept();
            });
}

void Connection::writeMessage(const std::string& message) {
    Logger::getInstance().logInfo(std::to_string(m_port) + " | Sending message");

    tcp::socket socket(m_ioContext);
    tcp::resolver resolver(m_ioContext);
    boost::asio::connect(socket, resolver.resolve("127.0.0.1", std::to_string(m_port)));

    boost::asio::write(socket, boost::asio::buffer(message, message.size()));
}
