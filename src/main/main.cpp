#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <boost/asio.hpp>
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

    boost::asio::io_context io_context;
    boost::asio::io_context::work work(io_context);
    boost::thread_group threads;

    Manager manager(settings.getRoutingAddresses(), io_context);

    return 0;
}