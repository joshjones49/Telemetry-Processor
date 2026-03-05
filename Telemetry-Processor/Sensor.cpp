#include "Sensor.h"

// Base sensor setup.
Sensor::Sensor(std::string name)
	: name_(std::move(name)),
	rng_(std::random_device{}()) { }

std::string Sensor::getName() const {
	return name_;
}

bool Sensor::isValid(double value) const {
	return true;
}

AltitudeSensor::AltitudeSensor(std::string name)
	: Sensor(std::move(name)) { }

// Sample from a normal distribution around cruise altitude.
double AltitudeSensor::readData() {
	std::normal_distribution<double> dist(20000.0, 300.0);
	return dist(rng_);
}

std::string AltitudeSensor::getType() const {
	return "Altitude";
}

VelocitySensor::VelocitySensor(std::string name)
	: Sensor(std::move(name)) { }

// Sample from a uniform speed range.
double VelocitySensor::readData() {
	std::uniform_real_distribution<double> dist(200.0, 600.0);
	return dist(rng_);
}

std::string VelocitySensor::getType() const {
	return "Velocity";
}

// Creates a concrete sensor by type name.
std::unique_ptr<Sensor> createSensor(const std::string& type, const std::string& name) {
	if (type == "Altitude") return std::make_unique<AltitudeSensor>(name);
	if (type == "Velocity") return std::make_unique<VelocitySensor>(name);

	throw std::invalid_argument("Unknown Sensor Type: " + type);
}