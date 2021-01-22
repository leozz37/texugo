#include "Logger.hpp"
#include <iostream>
#include <spdlog/sinks/rotating_file_sink.h>

Logger::Logger() noexcept
{
    const std::string logPath = "../../log/log.txt";

    try
    {
        auto logFile = spdlog::rotating_logger_mt("logFile", logPath, 1048576 * 5, 3);
        logFile->warn("LOG SYSTEM STARTED");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

void Logger::logInfo(const std::string& message)
{
    spdlog::info(message);
    spdlog::get("logFile")->info(message);
}

void Logger::logWarn(const std::string& message)
{
    spdlog::warn(message);
    spdlog::get("logFile")->warn(message);
}

void Logger::logWarn(const std::exception& message)
{
    spdlog::warn(message.what());
    spdlog::get("logFile")->warn(message.what());
}

void Logger::logError(const std::string& message)
{
    spdlog::error(message);
    spdlog::get("logFile")->error(message);
}

void Logger::logError(const std::exception& message)
{
    spdlog::error(message.what());
    spdlog::get("logFile")->error(message.what());
}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}