#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>
#include <chrono>
#include <iostream>

/**
 * Logger class - Thread-safe logging system with timestamps
 * 
 * Provides synchronized console output with formatted timestamps.
 * Uses RAII (mutex with lock_guard) to ensure thread-safety.
 * Suitable for multi-threaded telemetry processing applications.
 */
class Logger {
public:
    // Constructor - initializes the logger
    Logger();

    /**
     * Logs a message with timestamp to console
     * Thread-safe: multiple threads can call this simultaneously
     * 
     * @param message The text to log
     */
    void log(const std::string& message);

private:
    std::mutex mutex_;  // Protects console output from race conditions

    /**
     * Generates current timestamp in format: YYYY-MM-DD HH:MM:SS
     * @return Formatted timestamp string
     */
    std::string getTimestamp() const;
};

#endif