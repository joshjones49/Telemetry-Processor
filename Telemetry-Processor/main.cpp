#include "TelemetryProcessor.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "=== Simple Telemetry Processor ===\n\n";

    TelemetryProcessor processor;

    processor.addSensor(std::make_unique<AltitudeSensor>("Altimeter-1"));
    processor.addSensor(std::make_unique<VelocitySensor>("Pitot-Left"));

    try {
        processor.runSimulation(12, 400);  // 12 cycles, ~400 ms delay
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\nSimulation finished.\n";
    return 0;
}