# CMakeList.txt : CMake project for Telemetry-Processor, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Telemetry-Processor 
	"Telemetry-Processor.cpp" 
	"Telemetry-Processor.h" 
	"main.cpp" 
	"Sensor.h" 
	"Sensor.cpp" 
	"Logger.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Telemetry-Processor PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
