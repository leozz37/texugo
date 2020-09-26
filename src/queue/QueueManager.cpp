#include "texugo/process/QueueManager.hpp"

void QueueManager::processMessages() {
    while (1) {
        if (!m_processMessageQueue.empty()) {
            const std::string message = m_processMessageQueue.front();
            const short port = getDestination(message);
            insertConnectionQueue(message, port);
            m_processMessageQueue.pop();
        }
    }
}

void QueueManager::insertQueue(const std::string& message) {
    m_processMessageQueue.push(message);
}

void QueueManager::insertConnectionQueue(const std::string& message, short port) {
    // TODO: find connection on queue by name
}

short QueueManager::getDestination(const std::string& message) {
    // TODO: get destination from message
    return 5555;
}