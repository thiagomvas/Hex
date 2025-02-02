#include "Logger.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

std::string getColorForLevel(const std::string& level) {
    if (level == "INFO") {
        return "\033[32m"; // Green
    } else if (level == "ERROR") {
        return "\033[31m"; // Red
    } else if (level == "WARNING") {
        return "\033[33m"; // Yellow
    } else if (level == "DEBUG") {
        return "\033[34m"; // Blue
    } else if (level == "FATAL") {
        return "\033[35m"; // Magenta
    }
    return "\033[0m"; // Default color
}
namespace Hex {

Logger::Logger(std::ostream *out) : out(out) {}

        // General logging function
        void Logger::log(const std::string& message, const std::string& level, const char* file, int line, const char* function) {
            const time_t now = time(nullptr);
            char* dt = ctime(&now);
            dt[strlen(dt) - 1] = '\0';

            *out << getColorForLevel(level)
                 << "[" << dt << "] "
                 << "[" << level << "] "
                 << "[" << file << ":" << line << "] "
                 << "[" << function << "] " << "\033[0m" << std::endl
                 << "\t" << message << std::endl << std::endl;
        }

        // Log different levels with the file, line, and function details
        void Logger::logInfo(const std::string& message, const char* file, int line, const char* function) {
            log(message, "INFO", file, line, function);
        }

        void Logger::logError(const std::string& message, const char* file, int line, const char* function) {
            log(message, "ERROR", file, line, function);
        }

        void Logger::logWarning(const std::string& message, const char* file, int line, const char* function) {
            log(message, "WARNING", file, line, function);
        }

        void Logger::logDebug(const std::string& message, const char* file, int line, const char* function) {
            Logger::log(message, "DEBUG", file, line, function);
        }

        void Logger::logFatal(const std::string& message, const char* file, int line, const char* function) {
            log(message, "FATAL", file, line, function);
        }

    };

