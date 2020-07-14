#include "texugo/log/Logger.hpp"
#include <spdlog/sinks/rotating_file_sink.h>

void Logger::openLogFile(const std::string& logPath) {
    auto logFile = spdlog::rotating_logger_mt("log", logPath, 1048576 * 5, 3);
    logFile->info("LOG SYSTEM STARTED");
}

void Logger::logInfo(const std::string& message) {
    spdlog::info(message);
    spdlog::get("logFile")->info(message);
}

void Logger::logWarn(const std::string& message) {
    spdlog::warn(message);
    spdlog::get("logFile")->warn(message);
}

void Logger::logCritical(const std::string& message) {
    spdlog::critical(message);
    spdlog::get("logFile")->critical(message);
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

