#include <logging.hpp>

#include <memory>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace {
    using RGLA::Logger;
    class LoggerWrapper {
    public:
        LoggerWrapper(std::ostream& outStream, Logger::LoggerLevel level)
            : OutputStream(outStream)
            , Level(level)
        {}

        std::string GetCurrentTime() {
            const auto now = std::chrono::system_clock::now();
            const std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            std::stringstream out;
            out << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%I:%M:%S");
            return out.str();
        }
        std::string GetLevelString(Logger::LoggerLevel level) {
            switch (level) {
                case Logger::LoggerLevel::LOG_CRIT:
                    return "CRIT";
                case Logger::LoggerLevel::LOG_ERROR:
                    return "ERROR";
                case Logger::LoggerLevel::LOG_WARN:
                    return "WARN";
                case Logger::LoggerLevel::LOG_INFO:
                    return "INFO";
                case Logger::LoggerLevel::LOG_DEBUG:
                    return "DEBUG";
                case Logger::LoggerLevel::LOG_VERBOSE:
                    return "VERBOSE";
            }
            throw std::runtime_error("Unknown logging level");
        }

        std::ostream& OutputStream;
        Logger::LoggerLevel Level;
    };

    class NoopStream : public std::ostream {
    };
}

std::unique_ptr<LoggerWrapper> logger;

namespace RGLA {
    void Logger::InitLogger(std::ostream& outStream, LoggerLevel level) {
        logger = std::make_unique<LoggerWrapper>(outStream, level);
        std::cerr << "Logger pointer is " << logger.get() << std::endl;
    }

    std::ostream& Logger::Log(LoggerLevel level) {
        static NoopStream noopStream;

        if (!logger) {
            throw std::runtime_error("Logger is not initialized and cannot be used");
        }

        if (level < logger->Level) {
            return noopStream;
        }

        return logger->OutputStream << "[" << logger->GetCurrentTime() << "] [" << logger->GetLevelString(level) << "] ";
    }
}

