#include "Logger.h"
#include <sstream>
#include <iomanip>

// Default constructor - uses compiler-generated default behavior
Logger::Logger() = default;

/**
 * Thread-safe logging implementation
 * Uses RAII pattern: lock_guard acquires mutex on construction,
 * releases it on destruction (even if exception thrown)
 */
void Logger::log(const std::string& message) {
    // Acquire lock - blocks if another thread is logging
    // Automatically releases when lock_guard goes out of scope
    std::lock_guard<std::mutex> lock(mutex_);
    std::string line = "[" + getTimestamp() + "] " + message;
    std::cout << line << "\n";
}

/**
 * Generates formatted timestamp for log entries
 * Format: YYYY-MM-DD HH:MM:SS (e.g., 2024-02-13 17:46:20)
 */
std::string Logger::getTimestamp() const {
    // Get current system time as time_point
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for use with C-style time functions
    auto time = std::chrono::system_clock::to_time_t(now);

    // Convert to local time structure
    std::tm local = *std::localtime(&time);

    // Format timestamp using put_time manipulator
    std::ostringstream oss;
    oss << std::put_time(&local, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}