#ifndef TP_H
#define TP_H

#include "Sensor.h"
#include "Logger.h"
#include <vector>
#include <memory>
#include <chrono>
#include <thread>

/**
 * TelemetryProcessor - Main telemetry processing system
 * 
 * Manages a collection of sensors, reads data from them in cycles,
 * validates readings, checks thresholds, and logs all activity.
 */
class TelemetryProcessor {
public:
	/**
	 * Constructor - initializes the processor and logs startup
	 */
	TelemetryProcessor();

	// Destructor uses default behavior (RAII handles cleanup automatically)
	~TelemetryProcessor() = default;

	/**
	 * Adds a sensor to the processing system
	 * Takes ownership of the sensor via move semantics
	 * 
	 * @param sensor unique_ptr to a Sensor object (transfers ownership)
	 */
	void addSensor(std::unique_ptr<Sensor> sensor);

	/**
	 * Runs the telemetry simulation for a specified number of cycles
	 * Each cycle reads all sensors, validates data, and checks thresholds
	 * 
	 * @param num_cycles Number of read cycles to perform (default: 20)
	 * @param delay_ms Delay in milliseconds between cycles (default: 300)
	 */
	void runSim(int num_cycles = 20, int delay_ms = 300);

private:
	// Collection of sensors managed by unique_ptr (automatic cleanup)
	std::vector<std::unique_ptr<Sensor>> sensors_;

	// Thread-safe logger for recording events and readings
	Logger logger_;

	/**
	 * Reads data from all sensors in the collection
	 * Displays readings to console and logs them
	 * Called once per simulation cycle
	 */
	void processAllSensors();

	/**
	 * Checks if sensor readings exceed predefined thresholds
	 * Generates warnings for dangerous conditions:
	 * - Low altitude (< 5000 ft)
	 * - High velocity (> 550 knots)
	 * 
	 * @param value The sensor reading to check
	 * @param name Sensor identifier
	 * @param type Type of sensor ("Altitude" or "Velocity")
	 */
	void checkThresholds(double value, const std::string& name, const std::string& type);
};

#endif