# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#

# Require CMake version 3.10 or higher - provides modern CMake features
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
# This allows code changes to be applied while debugging without full rebuild
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  # Configure debug information format for Edit and Continue feature in Visual Studio
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Define the project name - used by IDEs and build systems
project ("Telemetry-Processor")

# Include sub-projects - adds the subdirectory containing the actual source code
# This allows for modular project structure with multiple components
add_subdirectory ("Telemetry-Processor")
