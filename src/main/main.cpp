#include "texugo/config/Settings.hpp"
#include "texugo/com/Manager.hpp"

int main(int argc, char** argv) {
    const std::string settingsPath = "../resources/settings.json";
    Settings settings(settingsPath);

    Manager manager(settings.getRoutingAddresses());

    return 0;
}
