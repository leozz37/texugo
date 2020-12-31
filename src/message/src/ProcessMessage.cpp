#include "message/ProcessMessage.hpp"
#include "com/ConnectionManager.hpp"
#include "message/MessageParser.hpp"

void ProcessMessage::processMessage(const std::string& payload)
{
    MessageParser parser(payload);
    const std::string&              message      = parser.getMessage();
    const std::vector<std::string>& destinations = parser.getDestination();
    insertConnectionQueue(message, destinations);
}


void ProcessMessage::insertConnectionQueue(const std::string&              message,
                                           const std::vector<std::string>& destinations)
{
    for (const auto& destination : destinations)
    {
        ConnectionManager::getInstance().insertConnectionQueue(destination, message);
    }
}
