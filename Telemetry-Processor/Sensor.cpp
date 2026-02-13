#include "Sensor.h"

#include <iostream>

Sensor::Sensor(std::string name)
	: name_(std::move(name)),
	rng_(std::random_device{}()) { }

std::string Sensor::getName() const {
	return name_;
}

bool Sensor::isValid(double value) const {
	return true;
}

/*-------------------------------
		ALTITUDE SENSOR
-------------------------------*/
class AltitudeSensor : public Sensor {
public:
	explicit AltitudeSensor(std::string name = "Altitude")
		: Sensor(std::move(name)) { }

	double readData() override {
		// Simulate altitude between 0 and 40kft with some noise
		std::normal_distribution<double> dist(20000.0, 300.0);
		return dist(rng_);
	}

	std::string getType() const override {
		return "Altitude";
	}
};

/*-------------------------------
		VELOCITY SENSOR
-------------------------------*/
class VelocitySensor : public Sensor {
public:
	explicit VelocitySensor(std::string name = "Airspeed")
		: Sensor(std::move(name)) { }

	double readData() override {
		// Simulate 200 - 600 knots
		std::uniform_real_distribution<double> dist(200.0, 600.0);
		return dist(rng_);
	}

	std::string getType() const override {
		return "Velocity";
	}
};

// Factory function
std::unique_ptr<Sensor> createSensor(const std::string& type, const std::string& name) {
	if (type == "Altitude") return std::make_unique<AltitudeSensor>(name);
	if (type == "Velocity") return std::make_unique<VelocitySensor>(name);
	throw std::invalid_argument("Unknown Sensor Type: " + type);
}