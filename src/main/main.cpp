#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/com/InputConnection.hpp"
#include "texugo/log/Logger.hpp"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <memory>

int main(int argc, char** argv) {
    Logger::getInstance().logWarn("STARTING TEXUGO");

    const std::string settingsPath = "../../resources/settings.json";
    Settings settings(settingsPath);

//    Manager manager(settings.getRoutingAddresses());
    boost::asio::io_context io_context;
    boost::thread_group threads;

    threads.create_thread(
            [ObjectPtr = InputConnection(io_context, short(5555))] {
                ObjectPtr.start();
            });

    threads.join_all();
    return 0;
}
