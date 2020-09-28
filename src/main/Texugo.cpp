#include "texugo/config/Settings.hpp"
#include "texugo/com/ConnectionManager.hpp"
#include "texugo/log/Logger.hpp"
#include <csignal>
#include <memory>

void signalHandling(int) {
    Logger::getInstance().logWarn("STOPPING TEXUGO");
    exit(0);
}

int main() {
    signal(SIGINT, signalHandling);

    Logger::getInstance().logWarn("STARTING TEXUGO");

    const std::string settingsPath = "../../resources/settings.json";
    Settings settings(settingsPath);

    boost::thread_group threads;

    // Start Connections
    threads.create_thread( [&]{
        ConnectionManager::getInstance().startConnections(
                settings.getReceiverAddresses(),
                settings.getSenderAddresses());
    } );

    threads.join_all();

    return 0;
}