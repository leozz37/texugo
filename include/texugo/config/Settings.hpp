#pragma once
#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

class Settings {
public:
    Settings(const std::string&);
    const std::string& getMongoPath() const;
    const std::string& getLogPath() const;
    const std::string& getMetricsAddress() const;
    const std::unordered_map<std::string, std::string>& getRoutingAddresses() const;

private:
    nlohmann::json getServerConfigs();
    void setRoutingAddresses(nlohmann::json data);

    std::string m_settingsPath;
    std::string m_mongoPath;
    std::string m_logPath;
    std::string m_metricsAddress;
    std::unordered_map<std::string, std::string> m_routingAddresses;
};
