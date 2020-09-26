#include "texugo/com/Connection.hpp"
#include "texugo/queue/ProcessQueue.hpp"

using boost::asio::ip::tcp;

// Session Methods
void Session::doRead() {
    auto self(shared_from_this());
    m_socket.async_read_some(boost::asio::buffer(m_data, maxLength),
                            [this, self](boost::system::error_code ec, std::size_t length) {
                                if (!ec) {
//                                    Logger::getInstance().logInfo(m_data);
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
    std::cout << message << "\n";
    m_messageQueue.push(message);
}
