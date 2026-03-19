#ifndef TP_H
#define TP_H

#include "Sensor.h"
#include "Logger.h"
#include <vector>
#include <memory>
#include <chrono>
#include <thread>

// Coordinates sensors, threshold checks, and logging.
class TelemetryProcessor {
public:
	// Logs processor startup.
	TelemetryProcessor();

	// overloaded contructor
	TelemetryProcessor(std::string name);

	// Default cleanup.
	~TelemetryProcessor() = default;

	// Adds a sensor and takes ownership.
	void addSensor(std::unique_ptr<Sensor> sensor);

	// Runs sensor polling for `num_cycles` with `delay_ms` pauses.
	void runSim(int num_cycles = 20, int delay_ms = 300);

	std::string getName() const noexcept;

private:
	// processor name
	std::string name_;

	// Owned sensor instances.
	std::vector<std::unique_ptr<Sensor>> sensors_;

	// Shared logger for all events.
	Logger logger_;

	// Reads, prints, checks, and logs all sensors once.
	void processAllSensors();

	// Emits warnings for low altitude and high velocity.
	void checkThresholds(double value, const std::string& name, const std::string& type);
};

#endif