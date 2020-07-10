#include "config/Settings.hpp"
#include "com/Manager.hpp"
#include "log/Logger.hpp"
#include "metrics/MetricsExporter.hpp"

int main(int argc, char** argv) {
    const std::string settingsPath = "src/data_store/config/settings.json";
    Settings settings(settingsPath);
    
    Logger::getInstance().openLogFile(settings.getLogPath());
    MetricsExporter::getInstance().start(settings.getMetricsAddress());

    Manager::getInstance().createConnections(settings.getRoutingAddresses());

    return 0;
}
