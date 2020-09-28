#include "texugo/config/Settings.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <utility>

Settings::Settings(std::string settingsPath)
: m_settingsPath(std::move(settingsPath))
{
    nlohmann::json data = getServerConfigs();
    m_metricsAddress    = data["settings"]["metricsAddress"];
    m_mongoPath         = data["settings"]["mongoPath"];
    m_logPath           = data["settings"]["logPath"];
    setReceiverAddresses(data);
    setSenderAddresses(data);
}

const std::string& Settings::getMongoPath() const { return m_mongoPath; }

const std::string& Settings::getLogPath() const { return m_logPath; }

const std::string& Settings::getMetricsAddress() const { return m_metricsAddress; }

const std::unordered_map<std::string, std::string>& Settings::getReceiverAddresses() const
{
    return m_receiverAddresses;
}

const std::unordered_map<std::string, std::string>& Settings::getSenderAddresses() const
{
    return m_senderAddresses;
}

void Settings::setReceiverAddresses(nlohmann::json data)
{
    for (const auto& address : data["receiverAddresses"])
    {
        auto dataAddress = address.get<std::map<std::string, std::string>>();
        m_receiverAddresses.insert(dataAddress.begin(), dataAddress.end());
    }
}

void Settings::setSenderAddresses(nlohmann::json data)
{
    for (const auto& address : data["senderAddresses"])
    {
        auto dataAddress = address.get<std::map<std::string, std::string>>();
        m_senderAddresses.insert(dataAddress.begin(), dataAddress.end());
    }
}

nlohmann::json Settings::getServerConfigs()
{
    std::ifstream i(m_settingsPath);
    std::string   jsonData
        = std::string(std::istreambuf_iterator<char>(i), std::istreambuf_iterator<char>());
    nlohmann::json serverConfig = nlohmann::json::parse(jsonData);
    return serverConfig;
}