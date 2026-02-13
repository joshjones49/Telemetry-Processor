#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>
#include <chrono>
#include <iostream>

class Logger {
public:
    Logger();
    void log(const std::string& message);

private:
    std::mutex mutex_;
    std::string getTimestamp() const;
};

#endif