#include <csignal>

#include "log/Logger.hpp"
#include "metrics/MetricsExporter.hpp"

int main(int argc, char** argv) {
    Logger::getInstance().openLogFile("log/log.txt");
    MetricsExporter::getInstance().start("127.0.0.1:8080");

    return 0;
}
