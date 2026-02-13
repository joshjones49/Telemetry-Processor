#ifndef TP_H
#define TP_H

#include "Sensor.h"
#include "Logger.h"
#include <vector>
#include <memory>
#include <chrono>
#include <thread>

class TelemetryProcessor {
public:
	TelemetryProcessor();
	~TelemetryProcessor() = default;

	void addSensor(std::unique_ptr<Sensor> sensor);
	void runSim(int num_cycles = 20, int delay_ms = 300);

private:
	std::vector<std::unique_ptr<Sensor>> sensors_;
	Logger logger_;

	void processAllSensors();
	void checkThresholds(double value, const std::string& name, const std::string& type);
};

#endif