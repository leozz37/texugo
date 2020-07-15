#pragma once
#include <string>
#include <queue>

class Connection {
public:
    Connection(const std::string&, const std::string&);
    void insertQueue(const std::string&);
    void removeQueue();
    const std::string &getName() const;
    const std::string &getPort() const;
    const std::queue<std::string> &getMessageQueue() const;
    void setWatermark(bool watermark);
    bool getWatermark() const;

private:
    bool m_watermark = false;
    std::string m_name;
    std::string m_port;
    std::queue<std::string> m_messageQueue;
};
