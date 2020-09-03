#include "texugo/com/InputConnection.hpp"

using boost::asio::ip::tcp;

// Session Methods
void Session::doRead() {
    auto self(shared_from_this());
    m_socket.async_read_some(boost::asio::buffer(m_data, maxLength),
                             [this, self](boost::system::error_code ec, std::size_t length) {
                                 if (!ec) {
                                     Logger::getInstance().logInfo("Message received");
                                     doWrite(length);
                                 }
                             });
}

void Session::doWrite(std::size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(m_socket, boost::asio::buffer("received", length),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                                 if (!ec) {
                                     doRead();
                                 }
                             });
}

// Class Methods
void Server::doAccept() {
    m_acceptor.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket))->start();
                }
                doAccept();
            });
}

// InputConnection
InputConnection::InputConnection(boost::asio::io_context& io_context, short port)
               : m_io_context(io_context), m_port(port) { }

void InputConnection::start() const {
    try {
        Server s(m_io_context, m_port);
        Logger::getInstance().logInfo("INPUT CNX OPENED AT: " + std::to_string(m_port));
        m_io_context.run();
    }
    catch (std::exception& e) {
        Logger::getInstance().logWarn(e.what());
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
