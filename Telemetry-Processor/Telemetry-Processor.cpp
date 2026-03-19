#include "Telemetry-Processor.h"

#include <iostream>
#include <iomanip>

std::string TelemetryProcessor::getName() const noexcept {
	return name_;
}

// overloaded contructor
TelemetryProcessor::TelemetryProcessor(std::string name) :
	TelemetryProcessor(std::move(name)) {
	logger_.log(name_ + " Processor Initialized");
}

// Log startup when processor is constructed.
TelemetryProcessor::TelemetryProcessor() {
	logger_.log(name_ + " Processor Initialized");
}

// Store a new sensor and record it.
void TelemetryProcessor::addSensor(std::unique_ptr<Sensor> sensor) {
	logger_.log("Processor: " + name_ + " Added Sensor: " + sensor->getName() + " (" + sensor->getType() + ")");

	sensors_.push_back(std::move(sensor));
}

// Run the polling loop.
void TelemetryProcessor::runSim(int num_cycles, int delay_ms) {
	logger_.log("Starting simulation - " + std::to_string(num_cycles) + " cycles");

	for (int i = 0; i < num_cycles; ++i) {
		std::cout << "\n--- Cycle " << (i + 1) << " ---\n";
		processAllSensors();
		std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
	}

	logger_.log("Simulation completed");
}

// Process sensors in parallel
void TelemetryProcessor::processAllSensors() {
	std::vector<std::thread> threads;

	for (const auto& sensor : sensors_) {
		threads.emplace_back([&logger = logger_, &sensor]() {
			double value = sensor->readData();
			// multiple threads calling log() at the same time
			logger.log(sensor->getName() + ": " + std::to_string(value));
		});
	}
	for (auto& t : threads) t.join();
}

// Emit alerts when readings cross fixed limits.
void TelemetryProcessor::checkThresholds(double value, const std::string& name, const std::string& type) {
	if (type == "Altitude" && value < 5000.0) {
		logger_.log("WARNING: Low Altitude Detected! " + name + " = " + std::to_string(value));
		std::cout << ">>> WARNING: LOW ALT <<<\n";
	}

	if (type == "Velocity" && value > 550.0) {
		logger_.log("ALERT: High Velocity! " + name + " = " + std::to_string(value));
		std::cout << ">>ALERT: HIGH VEL <<<\n";
	}
}