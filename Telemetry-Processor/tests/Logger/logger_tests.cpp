#include <gtest/gtest.h>
#include "../../Logger.h"


// SIMPLE TEST 1: Can we create a Logger?
TEST(LoggerSimpleTest, CanCreateLogger) {
    // Create a Logger object
    Logger logger;

    // SUCCEED() explicitly marks the test as passed
    SUCCEED();
}

// SIMPLE TEST 2: Can we log a message without crashing?
TEST(LoggerSimpleTest, CanLogMessage) {
    // Create a Logger
    Logger logger;

    // Try to log a simple message
    // EXPECT_NO_THROW checks that the code inside doesn't crash
    EXPECT_NO_THROW({
        logger.log("Hello, World!");
    });
}

// SIMPLE TEST 3: Can we log multiple messages?
TEST(LoggerSimpleTest, CanLogMultipleMessages) {
    Logger logger;

    // Log several messages - should all work fine
    EXPECT_NO_THROW({
        logger.log("First message");
        logger.log("Second message");
        logger.log("Third message");
    });
}

// SIMPLE TEST 4: Can we log an empty string?
TEST(LoggerSimpleTest, CanLogEmptyString) {
    Logger logger;

    // Even with empty string, should not crash
    EXPECT_NO_THROW({
        logger.log("");
    });
}

// SIMPLE TEST 5: Can we create multiple Loggers?
TEST(LoggerSimpleTest, CanCreateMultipleLoggers) {
    // Create three separate Logger objects
    Logger logger1;
    Logger logger2;
    Logger logger3;

    // All should work independently
    EXPECT_NO_THROW({
        logger1.log("Logger 1");
        logger2.log("Logger 2");
        logger3.log("Logger 3");
    });
}