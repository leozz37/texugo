#include "texugo/config/Settings.hpp"
#include "texugo/com/ConnectionManager.hpp"
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

    boost::thread_group threads;

    ConnectionManager manager;
    threads.create_thread( [&]{ manager.openConnections(settings.getRoutingAddresses()); } );

    threads.join_all();

    return 0;
}