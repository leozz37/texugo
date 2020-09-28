#pragma once
#include <queue>
#include <string>

class ProcessMessage {
public:
    void processMessage(const std::string&);

private:
    void insertConnectionQueue(const std::string&, const std::vector<std::string>&);

    inline static std::queue<std::string> m_processMessageQueue;
    bool m_running = true;
};