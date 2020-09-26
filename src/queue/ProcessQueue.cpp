#include "texugo/queue/ProcessQueue.hpp"
#include "texugo/log/Logger.hpp"
#include <iostream>

// Watch queue for coming messages
void ProcessQueue::watchMessages() {
    Logger::getInstance().logInfo("PROCESS QUEUE STARTED");
    while (m_running) {
        if (!m_processMessageQueue.empty()) {
            processMessage();
        }
    }
    Logger::getInstance().logWarn("PROCESS QUEUE STOPPED");
}

// Insert message on port queue and remove from process queue
void ProcessQueue::processMessage() {
    const std::string message = m_processMessageQueue.front();
    const short port = getDestination(message);
    insertConnectionQueue(message, port);
    m_processMessageQueue.pop();
}

// Watch queue for coming messages
void ProcessQueue::insertQueue(const std::string& message) {
    m_processMessageQueue.push(message);
}

void ProcessQueue::shutdown() {
    m_running = false;
}

void ProcessQueue::insertConnectionQueue(const std::string& message, short port) {
    // TODO: find connection on queue by name
    std::cout << "Message: " << message << " | Port: " << port << "\n";
}

short ProcessQueue::getDestination(const std::string& message) {
    // TODO: get destination from message
    return 3004;
}

ProcessQueue& ProcessQueue::getInstance() {
    static ProcessQueue instance;
    return instance;
}