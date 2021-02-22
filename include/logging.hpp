#pragma once

#include "common.hpp"

#include <iostream>

namespace RGLA {
    class Logger {
    public:
        enum class LoggerLevel {
            LOG_CRIT,
            LOG_ERROR,
            LOG_WARN,
            LOG_INFO,
            LOG_DEBUG,
            LOG_VERBOSE
        };

        static void InitLogger(std::ostream& outStream = std::cerr, LoggerLevel level = LoggerLevel::LOG_INFO);

        static std::ostream& Log(LoggerLevel level);

        static std::ostream& LogCrit() { return Log(LoggerLevel::LOG_CRIT); }
        static std::ostream& LogError() { return Log(LoggerLevel::LOG_ERROR); }
        static std::ostream& LogWarn() { return Log(LoggerLevel::LOG_WARN); }
        static std::ostream& LogInfo() { return Log(LoggerLevel::LOG_INFO); }
        static std::ostream& LogDebug() { return Log(LoggerLevel::LOG_DEBUG); }
        static std::ostream& LogVerbose() { return Log(LoggerLevel::LOG_VERBOSE); }
    };
}
