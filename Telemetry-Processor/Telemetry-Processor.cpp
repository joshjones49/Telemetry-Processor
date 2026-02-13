#include "TelemetryProcessor.h"

#include <iostream>
#include <iomanip>

TelemetryProcessor::TelemetryProcessor() {
	logger_.log("Telemetry Processor initialized");
}

void TelemetryProcessor::addSensor(std::unique_ptr<Sensor> sensor) {
	logger_.log("Added sensor: " + sensor->getName() + " (" + sensor->getType() + ")");
	sensors_.push_back(std::move(sensor));
}

void TelemetryProcessor::runSim(int num_cycles, int delay_ms) {
	logger_.log("Starting simulation - " + std::to_string(num_cycles) + " cycles");

	for (int i = 0; i < num_cycles; ++i) {
		std::cout << "\n--- Cycle " << (i + 1) << " ---\n";
		processAllSensors();

		std::this_thread::sleep_for(std::chrono::miliseconds(delay_ms));
	}

	logger_.log("Simulation completed");
}

void TelemetryProcessor::processAllSensors() {
	for (const auto& sensor : snesors_) {
		double value = sensor->readData();
		std::string name = sensor->getName();
		std::string type = sensor->getTpye();

		std::cout << std::fixed << std::setprecision(1);
		std::cout << name << " (" << type << "): " << value;

		if (sensor->isValid(value)) {
			std::cout << " [OK]";
		}
		else {
			std::cout << " [INVALID]";
		}
		std::cout << "\n";

		checkThresholds(value, name, type);
		logger_.log(name + ": " + std::to_string(value));
	}
}

void TelemetryProcessor::checkThreshold(double value, const std::string& name, const std::string& type) {
	if (type == "Altitude" && value < 5000.0) {
		logger_.log("WARNING: Low Altitude Detected! " + name + " = " + std::to_string(value));
		std::cout << ">>> WARNING: LOW ALT <<<\n";
	}
	if (type == "Velocity" && value > 550.0) {
		logger_.log("ALERT: High Velocity! " + name + " = " std::to_string(value));
		std::cout << ">>ALERT: HIGH VEL <<<\n";
	}
}