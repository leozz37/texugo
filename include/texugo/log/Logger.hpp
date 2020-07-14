#pragma once
#include <string>
#include <spdlog/spdlog.h>

class Logger {
public:
    Logger(const Logger& other) noexcept = delete;
    Logger(Logger&& other) noexcept = delete;
    Logger& operator = (const Logger& other) noexcept = delete;
    Logger& operator = (Logger&& other) noexcept = delete;

    void openLogFile(const std::string&);
    void logInfo(const std::string&);
    void logWarn(const std::string&);
    static Logger& getInstance();

private:
    Logger() noexcept = default;
};