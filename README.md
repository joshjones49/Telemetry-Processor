# Telemetry Processor – Aerospace Simulation Demo

Simple real-time telemetry processing simulation written in modern C++.

Demonstrates:
- RAII & smart pointers
- OOP (inheritance, polymorphism)
- Thread-safe logging
- Deterministic resource management
- Basic threshold alerting
- CMake build system
- Unit testing with Google Test

## Requirements

- **CMake** 3.10 or higher
- **C++20** compatible compiler:
  - Visual Studio 2019+ (MSVC)
  - GCC 10+
  - Clang 10+
- **Git** (for cloning and downloading Google Test)
- **Internet connection** (first build only - downloads Google Test automatically)

## Build & Run

### Quick Start (All Platforms)

```sh
# Clone the repository
git clone https://github.com/joshjones49/Telemetry-Processor.git
cd Telemetry-Processor

# Create build directory (IMPORTANT: from root, not subdirectory!)
mkdir build
cd build

# Configure CMake (downloads Google Test automatically)
cmake ..

# Build the project
cmake --build .

# Run the main application
# Windows:
.\Telemetry-Processor\Debug\Telemetry-Processor.exe

# Linux/macOS:
./Telemetry-Processor/Telemetry-Processor
```

### Windows (Visual Studio)

**Option 1: Command Line**
```powershell
mkdir build
cd build
cmake ..
cmake --build .
.\Telemetry-Processor\Debug\Telemetry-Processor.exe
```

**Option 2: Visual Studio IDE**
1. Open Visual Studio
2. **File → Open → Folder** → Select `Telemetry-Processor` folder
3. Wait for CMake to configure (watch Output window)
4. Press **Ctrl+F5** to build and run without debugging
5. Or press **F5** to debug

### Linux/macOS

```sh
mkdir build
cd build
cmake ..
make
./Telemetry-Processor/Telemetry-Processor
```

### Build Configurations

```sh
# Debug build (default)
cmake --build .

# Release build (optimized)
cmake --build . --config Release

# Clean rebuild
cmake --build . --target clean
cmake --build .
```

## Running Tests

The project includes unit tests using Google Test framework.

```sh
# From the build directory:

# Run tests with CTest
ctest --output-on-failure

# Or run the test executable directly
# Windows:
.\Telemetry-Processor\tests\Debug\Telemetry-Processor-Tests.exe

# Linux/macOS:
./Telemetry-Processor/tests/Telemetry-Processor-Tests
```

## Project Structure

```
Telemetry-Processor/
├── CMakeLists.txt              # Root CMake configuration
├── README.md
├── .gitignore
└── Telemetry-Processor/
    ├── CMakeLists.txt          # Project CMake configuration
    ├── main.cpp                # Entry point
    ├── Telemetry-Processor.h   # Main processor class
    ├── Telemetry-Processor.cpp
    ├── Sensor.h                # Sensor hierarchy
    ├── Sensor.cpp
    ├── Logger.h                # Thread-safe logger
    ├── Logger.cpp
    └── tests/
        ├── CMakeLists.txt      # Test configuration
        ├── test_main.cpp       # Test entry point
        ├── Logger/
        │   ├── logger_tests.h
        │   └── logger_tests.cpp
        ├── Sensor/
        │   ├── sensor_tests.h
        │   └── sensor_tests.cpp
        └── TelPro/
            ├── telpro_tests.h
            └── telpro_tests.cpp
```

## Features

- **Polymorphic Sensor System**: Extensible sensor hierarchy supporting multiple types
- **Statistical Simulation**: Normal and uniform distributions for realistic data
- **Thread-Safe Logging**: Mutex-protected timestamped logging
- **Threshold Monitoring**: Real-time alerting for safety-critical conditions
- **Memory Safety**: Smart pointers and RAII for automatic resource management
- **Factory Pattern**: Dynamic sensor creation without exposing instantiation logic

## Troubleshooting

### "Could not find GTest" error
- Ensure you have an **internet connection** during first build
- CMake automatically downloads Google Test via FetchContent
- If it fails, delete `build/` and try again

### Build from wrong directory
- Always build from the **root** `Telemetry-Processor/` directory
- Create `build/` at root level, not in subdirectories

### IntelliSense errors in Visual Studio
- Go to **Project → Delete Cache and Reconfigure**
- Or close and reopen Visual Studio
- Errors should disappear after CMake reconfigures

### Clean rebuild
```sh
# Delete build directory and start fresh
rm -rf build  # Linux/macOS
# or
Remove-Item -Recurse -Force build  # Windows PowerShell

mkdir build
cd build
cmake ..
cmake --build .
```

## License

This project is provided as-is for educational and demonstration purposes.