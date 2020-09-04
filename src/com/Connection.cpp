#include "texugo/com/Connection.hpp"
#include <iostream>
#include <utility>

Connection::Connection(std::string  name, std::string  port) : m_name(std::move(name)), m_port(std::move(port)) { }

void Connection::insertQueue(const std::string& message) {
    if (!m_watermark) {
        if (m_messageQueue.size() >= 20) {
            m_watermark = true;
//            rejectMessage();
        }
        else {
            m_messageQueue.push(message);
        }
    }
    else {
        if (m_messageQueue.size() <= 19) {
            m_watermark = false;
            m_messageQueue.push(message);
        }
        else {
//            rejectMessage();
        }
    }
}

void Connection::removeQueue() {
    m_messageQueue.pop();

    if (m_messageQueue.size() <= 19) {
        m_watermark = false;
    }
}

const std::string &Connection::getName() const {
    return m_name;
}

const std::string &Connection::getPort() const {
    return m_port;
}

const std::queue<std::string> &Connection::getMessageQueue() const {
    return m_messageQueue;
}

void Connection::setWatermark(bool watermark) {
    m_watermark = watermark;
}

bool Connection::getWatermark() const {
    return m_watermark;
}