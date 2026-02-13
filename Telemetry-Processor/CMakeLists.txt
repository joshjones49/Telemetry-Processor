# CMakeList.txt : CMake project for Telemetry-Processor, include source and define
# project specific logic here.
#

# Specify minimum CMake version required for this project
cmake_minimum_required(VERSION 3.10)

# Define the project name - creates the Telemetry-Processor target
project("Telemetry-Processor")

# Create an executable target from the specified source files
# Lists all .cpp implementation files and .h header files
# CMake will compile the .cpp files and link them into an executable
add_executable (Telemetry-Processor 
	"Telemetry-Processor.cpp"   # Main processor implementation
	"Telemetry-Processor.h"     # Main processor header
	"main.cpp"                  # Program entry point
	"Sensor.h"                  # Sensor class declarations
	"Sensor.cpp"                # Sensor implementations
	"Logger.h"                  # Logger class declaration
	"Logger.cpp"                # Logger implementation
)

# Set C++20 standard if CMake version supports it (3.12+)
# Enables modern C++ features like concepts, ranges, and designated initializers
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Telemetry-Processor PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
