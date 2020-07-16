#include "texugo/log/Logger.hpp"
#include <iostream>
#include <spdlog/sinks/rotating_file_sink.h>

void Logger::openLogFile(const std::string& logPath) {
    try {
        auto logFile = spdlog::rotating_logger_mt("logFile", logPath, 1048576 * 5, 3);
        logFile->warn("LOG SYSTEM STARTED");
    }
    catch (const spdlog::spdlog_ex &ex) {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

void Logger::logInfo(const std::string& message) {
    spdlog::info(message);
    spdlog::get("logFile")->info(message);
}

void Logger::logWarn(const std::string& message) {
    spdlog::warn(message);
    spdlog::get("logFile")->warn(message);
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

