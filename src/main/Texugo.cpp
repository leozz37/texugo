#include "texugo/config/Settings.hpp"
#include "texugo/com/ConnectionManager.hpp"
#include "texugo/log/Logger.hpp"
#include <csignal>
#include <memory>

void signalHandling(int)
{
    Logger::getInstance().logWarn("STOPPING TEXUGO");
    exit(0);
}

int main()
{
    // Handler exit signal
    signal(SIGINT, signalHandling);

    Logger::getInstance().logWarn("STARTING TEXUGO");

    // Getting config from file
    // TODO: save config to mongo?
    const std::string settingsPath = "../../resources/settings.json";
    Settings          settings(settingsPath);

    // Creating threads group
    boost::thread_group threads;

    // Creating Receiver/Sender Connections
    ConnectionManager::getInstance().createConnections(settings.getReceiverAddresses(),
                                                       settings.getSenderAddresses());

    // Starting Receiver Connections
    threads.create_thread([&] { ConnectionManager::getInstance().startConnections(); });
    threads.join_all();

    return 0;
}