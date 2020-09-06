#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <csignal>
#include <memory>

void signalHandling(int signalNum) {
    Logger::getInstance().logWarn("STOPING TEXUGO");
    exit(0);
}

int main() {
    signal(SIGINT, signalHandling);

    Logger::getInstance().logWarn("STARTING TEXUGO");

    const std::string settingsPath = "../../resources/settings.json";
    Settings settings(settingsPath);

    Manager manager(settings.getRoutingAddresses());

    return 0;
}