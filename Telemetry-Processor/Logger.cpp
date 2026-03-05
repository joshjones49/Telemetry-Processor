#include "Logger.h"
#include <sstream>
#include <iomanip>

// No custom setup needed.
Logger::Logger() = default;

// std::lock_guard acquires mutex_ here and releases it automatically
// when the function scope ends, so each log call prints as one atomic line.
void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::string line = "[" + getTimestamp() + "] " + message;
    std::cout << line << "\n";
}

// Build "YYYY-MM-DD HH:MM:SS" in four steps:
// 1) capture current system_clock time_point
// 2) convert to time_t for C time APIs
// 3) convert to local broken-down time (std::tm)
// 4) format with std::put_time into an output string
std::string Logger::getTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm local = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&local, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}