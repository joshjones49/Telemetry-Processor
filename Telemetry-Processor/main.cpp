#include "Telemetry-Processor.h"
#include <iostream>
#include <memory>

// Run a short telemetry simulation.
int main() {
    std::cout << "=== Simple Telemetry Processor ===\n\n";

    TelemetryProcessor processor;

    // Register sensors.
    processor.addSensor(std::make_unique<AltitudeSensor>("Altimeter-1"));
    processor.addSensor(std::make_unique<VelocitySensor>("Pitot-Left"));

    try {
        processor.runSim(5, 5000);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\nSimulation finished.\n";
    return 0;
}