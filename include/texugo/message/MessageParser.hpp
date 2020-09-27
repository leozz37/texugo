#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

class MessageParser {
public:
    explicit MessageParser(const std::string&);
    const std::vector<std::string> &getDestination() const;
    const std::string &getMessage() const;

private:
    std::vector<std::string> m_destination;
    std::string m_message;
};