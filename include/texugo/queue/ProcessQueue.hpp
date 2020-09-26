#pragma once
#include <queue>
#include <string>

class ProcessQueue {
public:
    ProcessQueue(const ProcessQueue& other) noexcept = delete;
    ProcessQueue(ProcessQueue&& other) noexcept = delete;
    ProcessQueue& operator = (const ProcessQueue& other) noexcept = delete;
    ProcessQueue& operator = (ProcessQueue&& other) noexcept = delete;

    void watchMessages();
    void insertQueue(const std::string&);
    void shutdown();
    static ProcessQueue& getInstance();

private:
    ProcessQueue() noexcept = default;

    void processMessage();
    void insertConnectionQueue(const std::string&);

    std::queue<std::string> m_processMessageQueue;
    bool m_running = true;
};