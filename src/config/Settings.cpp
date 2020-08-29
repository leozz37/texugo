#include "texugo/config/Settings.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <utility>

Settings::Settings(std::string  settingsPath) : m_settingsPath(std::move(settingsPath)) {
    nlohmann::json data = getServerConfigs();
    m_metricsAddress = data["settings"]["metricsAddress"];
    m_mongoPath = data["settings"]["mongoPath"];
    m_logPath = data["settings"]["logPath"];
    setRoutingAddresses(data);
}

const std::string &Settings::getMongoPath() const {
    return m_mongoPath;
}

const std::string &Settings::getLogPath() const {
    return m_logPath;
}

const std::string &Settings::getMetricsAddress() const {
    return m_metricsAddress;
}

const std::unordered_map<std::string, std::string> &Settings::getRoutingAddresses() const {
    return m_routingAddresses;
}

void Settings::setRoutingAddresses(nlohmann::json data) {
    for (const auto& address : data["routingAddresses"]) {
        auto dataAddress = address.get<std::map<std::string, std::string>>();
        m_routingAddresses.insert(dataAddress.begin(), dataAddress.end());
    }
}

nlohmann::json Settings::getServerConfigs() {
    std::ifstream i(m_settingsPath);
    std::string jsonData = std::string(std::istreambuf_iterator<char>(i), std::istreambuf_iterator<char>());
    nlohmann::json serverConfig = nlohmann::json::parse(jsonData);
    return serverConfig;
}
