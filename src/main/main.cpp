#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"
#include "texugo/com/InputConnection.hpp"

int main(int argc, char** argv) {
    const std::string settingsPath = "../../resources/settings.json";
    Settings settings(settingsPath);

    Manager manager(settings.getRoutingAddresses());

    InputConnection inputConnection((short)5555);

    return 0;
}
