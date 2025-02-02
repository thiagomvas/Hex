#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstring>



namespace Hex {

  class Logger {
  public:
    Logger(std::ostream *out);

    // General logging function
    void log(const std::string& message, const std::string& level, const char* file, int line, const char* function);

    // Log different levels with the file, line, and function details
    void logInfo(const std::string& message, const char* file, int line, const char* function);

    void logError(const std::string& message, const char* file, int line, const char* function);

    void logWarning(const std::string& message, const char* file, int line, const char* function);

    void logDebug(const std::string& message, const char* file, int line, const char* function);

    void logFatal(const std::string& message, const char* file, int line, const char* function);

  private:
    std::ostream* out;
  };

} // namespace Hex

#endif // LOGGER_H
