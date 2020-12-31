#pragma once
#include <string>
#include <spdlog/spdlog.h>

class Logger
{
public:
    Logger(const Logger& other) noexcept = delete;
    Logger(Logger&& other) noexcept      = delete;
    Logger& operator=(const Logger& other) noexcept = delete;
    Logger& operator=(Logger&& other) noexcept = delete;

    void           openLogFile();
    void           logInfo(const std::string&);
    void           logWarn(const std::string&);
    void           logWarn(const std::exception&);
    void           logError(const std::string&);
    void           logError(const std::exception&);
    static Logger& getInstance();

private:
    Logger() noexcept;
};