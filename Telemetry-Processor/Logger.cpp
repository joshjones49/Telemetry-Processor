#include "Logger.h"
#include <sstream>
#include <iomanip>

Logger::Logger() = default;

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex_);

    std::string line = "[" + getTimestamp() + "] " + message;
    std::cout << line << "\n";
}

std::string Logger::getTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm local = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&local, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}