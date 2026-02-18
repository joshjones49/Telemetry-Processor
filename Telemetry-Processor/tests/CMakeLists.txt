# Create test executable
add_executable(Telemetry-Processor-Tests
	test_main.cpp
	Logger/logger_tests.cpp
	Sensor/sensor_tests.cpp
	TelPro/telpro_tests.cpp
	# Include source files that tests depend on
	../Sensor.cpp
	../Logger.cpp
	../Telemetry-Processor.cpp
)

# Link with Google Test and set include directories
target_link_libraries(Telemetry-Processor-Tests
	PRIVATE
	GTest::gtest_main
	GTest::gtest
)

# Allow tests to find the headers
target_include_directories(Telemetry-Processor-Tests
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Set C++20 standard for tests
set_property(TARGET Telemetry-Processor-Tests PROPERTY CXX_STANDARD 20)

# Discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(Telemetry-Processor-Tests)