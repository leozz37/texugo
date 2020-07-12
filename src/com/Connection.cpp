#include "texugo/com/Connection.hpp"

Connection::Connection(const std::string& name, const std::string& port) : m_name(name), m_port(port) { }

void Connection::insertQueue(const std::string& message) {
    if (!m_watermark) {
        if (m_messageQueue.size() >= 20) {
            m_watermark = true;
            rejectMessage();
        }
        else {
            m_messageQueue.push(message);
        }
    }
    else {
        if (m_messageQueue.size() < 20) {
            m_watermark = true;
            m_messageQueue.push(message);
        }
        else {
            rejectMessage();
        }
    }
}

void Connection::rejectMessage() {
    // TODO create reject message system
}

const std::string &Connection::getName() const {
    return m_name;
}

const std::string &Connection::getPort() const {
    return m_port;
}
