#pragma once
#include <string>
#include <queue>

class Connection {
public:
    Connection(const std::string&, const std::string&);
    const std::string &getName() const;
    const std::string &getPort() const;
    void insertQueue(const std::string&);
    void rejectMessage();

private:
    bool m_watermark;
    std::string m_name;
    std::string m_port;
    std::queue<std::string> m_messageQueue;
};
