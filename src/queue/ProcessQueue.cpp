#include "texugo/queue/ProcessQueue.hpp"
#include "texugo/com/ConnectionManager.hpp"
#include "texugo/message/MessageParser.hpp"
#include "texugo/log/Logger.hpp"

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
    insertConnectionQueue(message);
    m_processMessageQueue.pop();
}

// Watch queue for coming messages
void ProcessQueue::insertQueue(const std::string& message) {
    m_processMessageQueue.push(message);
}

void ProcessQueue::shutdown() {
    m_running = false;
}

void ProcessQueue::insertConnectionQueue(const std::string& payload) {
    MessageParser parser(payload);

    const std::string& message = parser.getMessage();
    const std::vector<std::string>& destinations = parser.getDestination();

    for (const auto& destination : destinations) {
        ConnectionManager::getInstance().insertConnectionQueue(destination, message);
    }
}

ProcessQueue& ProcessQueue::getInstance() {
    static ProcessQueue instance;
    return instance;
}