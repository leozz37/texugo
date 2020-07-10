#include <texugo/config/Settings.hpp>
#include <texugo/com/Manager.hpp>
#include <texugo/log/Logger.hpp>
#include <texugo/metrics/MetricsExporter.hpp>

int main(int argc, char** argv) {
    const std::string settingsPath = "config/settings.json";
    Settings settings(settingsPath);
    
    Logger::getInstance().openLogFile(settings.getLogPath());
    MetricsExporter::getInstance().start(settings.getMetricsAddress());

    Manager::getInstance().createConnections(settings.getRoutingAddresses());

    return 0;
}
