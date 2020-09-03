#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <boost/asio.hpp>
#include <memory>

int main() {
    Logger::getInstance().logWarn("STARTING TEXUGO");

    const std::string settingsPath = "../../resources/settings.json";
    Settings settings(settingsPath);

    boost::asio::io_context io_context;
    boost::asio::io_context::work work(io_context);
    Manager manager(settings.getRoutingAddresses(), io_context);

    return 0;
}