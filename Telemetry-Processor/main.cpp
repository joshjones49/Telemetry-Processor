#include "Telemetry-Processor.h"
#include <iostream>
#include <memory>

/**
 * Main entry point for the Telemetry Processor simulation
 * 
 * Creates a telemetry processor, adds sensors to it, and runs
 * a simulation to demonstrate sensor reading and threshold checking.
 */
int main() {
    std::cout << "=== Simple Telemetry Processor ===\n\n";

    // Create the main processor object (manages sensors and logging)
    TelemetryProcessor processor;

    // Add sensors using smart pointers (automatic memory management)
    // std::make_unique creates the sensor and wraps it in unique_ptr
    // Ownership transfers to processor via move semantics
    processor.addSensor(std::make_unique<AltitudeSensor>("Altimeter-1"));
    processor.addSensor(std::make_unique<VelocitySensor>("Pitot-Left"));

    // Run simulation with exception handling
    try {
        // Execute 12 cycles with 400ms delay between each
        // Each cycle: read all sensors, validate, check thresholds, log
        processor.runSim(12, 400);
    }
    catch (const std::exception& e) {
        // Catch any runtime errors and display error message
        std::cerr << "Error: " << e.what() << "\n";
        return 1;  // Return error code
    }

    std::cout << "\nSimulation finished.\n";
    return 0;  // Success
}