# Telemetry Processor – Aerospace Simulation Demo

Simple real-time telemetry processing simulation written in modern C++.

Demonstrates:
- RAII & smart pointers
- OOP (inheritance, polymorphism)
- Thread-safe logging
- Deterministic resource management
- Basic threshold alerting
- CMake build system

## Build & Run

### Windows (Visual Studio)
```sh
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\Telemetry-Processor.exe
```

**Or in Visual Studio:** Open the folder in VS, press **Ctrl+F5** to build and run.

### Linux/macOS
```sh
mkdir build
cd build
cmake ..
make
./Telemetry-Processor
```

### Platform-Agnostic
```sh
mkdir build
cd build
cmake ..
cmake --build .               # Works on all platforms
cmake --build . --config Release  # For optimized build
```

**Run:**
- Windows: `.\Debug\Telemetry-Processor.exe`
- Linux/macOS: `./Telemetry-Processor`