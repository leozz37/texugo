#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"

int main(int argc, char** argv) {
    const std::string settingsPath = "../resources/settings.json";
    Settings settings(settingsPath);

    Logger::getInstance().openLogFile(settings.getLogPath());
    Manager manager(settings.getRoutingAddresses());

    return 0;
}
