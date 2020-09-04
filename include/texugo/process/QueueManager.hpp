#pragma once
#include <queue>
#include <string>

class QueueManager {
public:
    void processMessages();
    void insertQueue(const std::string&);
    void insertConnectionQueue(const std::string&, short);
    short getDestination(const std::string&);

private:
    std::queue<std::string> m_processMessageQueue;
};