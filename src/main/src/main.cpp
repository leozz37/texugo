#include <csignal>

#include "log/Logger.hpp"

int main(int argc, char** argv) {
    Logger::getInstance().openLogFile("log/log.txt");

    return 0;
}
