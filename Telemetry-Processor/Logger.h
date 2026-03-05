#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>
#include <chrono>
#include <iostream>

// Thread-safe console logger with timestamps.
class Logger {
public:
    // Default constructor.
    Logger();

    // Writes one timestamped line.
    void log(const std::string& message);

private:
    std::mutex mutex_;

    // Formats the current local time.
    std::string getTimestamp() const;
};

#endif