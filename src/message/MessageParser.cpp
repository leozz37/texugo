#include "texugo/message/MessageParser.hpp"
#include "texugo/log/Logger.hpp"

MessageParser::MessageParser(const std::string& message) {
    try {
        nlohmann::json payload = nlohmann::json::parse(message);
        m_message     = payload["message"];
        auto element = payload["destination"];
        std::copy(element.begin(), element.end(), back_inserter(m_destination));
    }
    catch (const std::exception& e) {
        Logger::getInstance().logWarn(e);
        return;
    }
}

const std::vector<std::string> &MessageParser::getDestination() const {
    return m_destination;
}

const std::string &MessageParser::getMessage() const {
    return m_message;
}
