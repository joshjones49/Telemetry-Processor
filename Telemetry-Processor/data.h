#pragma once
#include<map>
#include<string>
#include "Telemetry-Processor.h"

// data for the 3 processors
std::map<std::string, std::string> ArrowData{
	{"Arrow-F", "Altitude"},
	{"Arrow-R", "Altitude"},
	{"Arrow-U", "Velocity"},
};

std::map<std::string, std::string> ShieldData{
	{"Shield-1", "Velocity"},
	{"Shield-2", "Altitude"},
	{"Shield-3", "Velocity"},
};

std::map<std::string, std::string> SwordData{
	{"Sword-N", "Altitude"},
	{"Sword-S", "Altitude"},
	{"Sword-U", "Velocity"},
};

// function to put sensor data into processors and use the runSim() function
void createSensorsRunSim(std::string name, std::map<std::string, std::string>& m) {
	TelemetryProcessor p(name);
	for (auto& pair : m) {
		if (pair.second == "Velocity") {
			p.addSensor(std::make_unique<VelocitySensor>(pair.first));
		}
		else {
			p.addSensor(std::make_unique<AltitudeSensor>(pair.first));
		}
	}
	p.runSim(3, 3000);
}