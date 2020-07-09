#include "config/Settings.hpp"
#include "log/Logger.hpp"
#include "metrics/MetricsExporter.hpp"

int main(int argc, char** argv) {
    Settings settings("src/data_store/config/settings.json");
    Logger::getInstance().openLogFile(settings.getLogPath());
    MetricsExporter::getInstance().start(settings.getMetricsAddress());
    return 0;
}
