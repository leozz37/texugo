#include "SenderConnection.hpp"
#include "Logger.hpp"

using boost::asio::ip::tcp;

SenderConnection::SenderConnection(boost::asio::io_context& io_context, short port)
: m_ioContext(io_context)
, m_port(port)
{
}


void SenderConnection::writeMessage(const std::string& message)
{
    try
    {
        Logger::getInstance().logInfo(std::to_string(m_port) + " | Sending message");
        tcp::socket   socket(m_ioContext);
        tcp::resolver resolver(m_ioContext);
        boost::asio::connect(socket, resolver.resolve({ "127.0.0.1", std::to_string(m_port) }));
        boost::asio::write(socket, boost::asio::buffer(message, message.size()));
    }
    catch (std::exception& e)
    {
        Logger::getInstance().logError(e);
    }
}