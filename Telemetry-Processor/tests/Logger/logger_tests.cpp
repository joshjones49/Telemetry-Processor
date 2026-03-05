#include <gtest/gtest.h>
#include "../../Logger.h"

// Basic logger behavior.
TEST(LoggerSimpleTest, CanCreateLogger) {
    Logger logger;
    SUCCEED();
}

TEST(LoggerSimpleTest, CanLogMessage) {
    Logger logger;

    EXPECT_NO_THROW({
        logger.log("Hello, World!");
    });
}

TEST(LoggerSimpleTest, CanLogMultipleMessages) {
    Logger logger;

    EXPECT_NO_THROW({
        logger.log("First message");
        logger.log("Second message");
        logger.log("Third message");
    });
}

TEST(LoggerSimpleTest, CanLogEmptyString) {
    Logger logger;

    EXPECT_NO_THROW({
        logger.log("");
    });
}

TEST(LoggerSimpleTest, CanCreateMultipleLoggers) {
    Logger logger1;
    Logger logger2;
    Logger logger3;

    EXPECT_NO_THROW({
        logger1.log("Logger 1");
        logger2.log("Logger 2");
        logger3.log("Logger 3");
    });
}