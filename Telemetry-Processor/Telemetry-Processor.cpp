#include "Telemetry-Processor.h"

#include <iostream>
#include <iomanip>

/**
 * Constructor - initializes the processor and logs startup
 * Logger is automatically initialized by default constructor
 */
TelemetryProcessor::TelemetryProcessor() {
	logger_.log("Telemetry Processor initialized");
}

/**
 * Adds a sensor to the processing system
 * Takes ownership via move semantics - caller can no longer use the pointer
 * 
 * @param sensor unique_ptr to sensor (ownership transferred to sensors_ vector)
 */
void TelemetryProcessor::addSensor(std::unique_ptr<Sensor> sensor) {
	// Log the addition before moving (after move, pointer is null)
	logger_.log("Added sensor: " + sensor->getName() + " (" + sensor->getType() + ")");

	// Transfer ownership to the vector (sensor pointer becomes null after this)
	sensors_.push_back(std::move(sensor));
}

/**
 * Runs the main simulation loop
 * Each cycle: reads all sensors, displays readings, checks thresholds
 * Pauses between cycles to simulate real-time data acquisition
 * 
 * @param num_cycles Number of reading cycles to perform
 * @param delay_ms Milliseconds to wait between cycles
 */
void TelemetryProcessor::runSim(int num_cycles, int delay_ms) {
	logger_.log("Starting simulation - " + std::to_string(num_cycles) + " cycles");

	// Main simulation loop
	for (int i = 0; i < num_cycles; ++i) {
		// Display cycle header
		std::cout << "\n--- Cycle " << (i + 1) << " ---\n";

		// Read and process all sensors
		processAllSensors();

		// Simulate real-time delay between readings (e.g., sensor sampling rate)
		std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
	}

	logger_.log("Simulation completed");
}

/**
 * Processes all registered sensors
 * Reads data, validates it, displays it, and checks thresholds
 * Demonstrates polymorphism - works with any Sensor-derived type
 */
void TelemetryProcessor::processAllSensors() {
	// Iterate through all sensors using range-based for loop
	// auto& deduces type as unique_ptr<Sensor>&
	for (const auto& sensor : sensors_) {
		// Read data from sensor (polymorphic call - actual type determined at runtime)
		double value = sensor->readData();
		std::string name = sensor->getName();
		std::string type = sensor->getType();

		// Format output: 1 decimal place precision
		std::cout << std::fixed << std::setprecision(1);
		std::cout << name << " (" << type << "): " << value;

		// Validate reading and display status
		if (sensor->isValid(value)) {
			std::cout << " [OK]";
		}
		else {
			std::cout << " [INVALID]";
		}
		std::cout << "\n";

		// Check for dangerous conditions
		checkThresholds(value, name, type);

		// Log the reading for record-keeping
		logger_.log(name + ": " + std::to_string(value));
	}
}

/**
 * Checks sensor readings against predefined safety thresholds
 * Issues warnings/alerts when dangerous conditions are detected
 * 
 * Thresholds:
 * - Altitude < 5000 ft: Low altitude warning (terrain proximity)
 * - Velocity > 550 knots: High velocity alert (exceeding safe limits)
 * 
 * @param value The sensor reading to check
 * @param name Sensor identifier for logging
 * @param type Sensor type to determine which threshold to check
 */
void TelemetryProcessor::checkThresholds(double value, const std::string& name, const std::string& type) {
	// Check altitude threshold
	if (type == "Altitude" && value < 5000.0) {
		// Log warning for low altitude condition
		logger_.log("WARNING: Low Altitude Detected! " + name + " = " + std::to_string(value));
		// Display alert to console
		std::cout << ">>> WARNING: LOW ALT <<<\n";
	}

	// Check velocity threshold
	if (type == "Velocity" && value > 550.0) {
		// Log alert for high velocity condition
		logger_.log("ALERT: High Velocity! " + name + " = " + std::to_string(value));
		// Display alert to console
		std::cout << ">>ALERT: HIGH VEL <<<\n";
	}
}