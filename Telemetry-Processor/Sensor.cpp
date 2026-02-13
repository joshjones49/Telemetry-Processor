#include "Sensor.h"

#include <iostream>

/*-------------------------------
	BASE SENSOR CLASS
-------------------------------*/

/**
 * Base Sensor constructor
 * Initializes the sensor name and seeds the random number generator
 * Uses std::move for efficient string transfer (avoids copying)
 */
Sensor::Sensor(std::string name)
	: name_(std::move(name)),              // Move name to avoid copy
	rng_(std::random_device{}()) { }       // Seed RNG with true random value

/**
 * Returns the sensor's unique identifier
 */
std::string Sensor::getName() const {
	return name_;
}

/**
 * Basic validation - always returns true in this implementation
 * Could be overridden in derived classes for specific validation logic
 * (e.g., check if altitude is within physically possible bounds)
 */
bool Sensor::isValid(double value) const {
	return true;
}

/*-------------------------------
	ALTITUDE SENSOR
-------------------------------*/

/**
 * AltitudeSensor constructor
 * Passes name to base Sensor constructor via initializer list
 */
AltitudeSensor::AltitudeSensor(std::string name)
	: Sensor(std::move(name)) { }

/**
 * Simulates altitude reading using normal distribution
 * Mean: 20,000 ft (typical cruising altitude)
 * Std Dev: 300 ft (realistic sensor noise/variation)
 * Range: Approximately 19,100 - 20,900 ft (within 3 standard deviations)
 */
double AltitudeSensor::readData() {
	// Create normal distribution (Gaussian curve)
	std::normal_distribution<double> dist(20000.0, 300.0);

	// Generate and return random value from distribution
	return dist(rng_);
}

/**
 * Returns sensor type identifier for polymorphic behavior
 */
std::string AltitudeSensor::getType() const {
	return "Altitude";
}

/*-------------------------------
	VELOCITY SENSOR
-------------------------------*/

/**
 * VelocitySensor constructor
 * Passes name to base Sensor constructor via initializer list
 */
VelocitySensor::VelocitySensor(std::string name)
	: Sensor(std::move(name)) { }

/**
 * Simulates velocity/airspeed reading using uniform distribution
 * Range: 200 - 600 knots
 * All values within range have equal probability
 * Typical for commercial/military aircraft speed range
 */
double VelocitySensor::readData() {
	// Create uniform distribution (flat probability across range)
	std::uniform_real_distribution<double> dist(200.0, 600.0);

	// Generate and return random value from distribution
	return dist(rng_);
}

/**
 * Returns sensor type identifier for polymorphic behavior
 */
std::string VelocitySensor::getType() const {
	return "Velocity";
}

/*-------------------------------
	FACTORY FUNCTION
-------------------------------*/

/**
 * Factory function for creating sensors dynamically
 * Demonstrates Factory design pattern - creates objects without
 * exposing the instantiation logic to the client
 * 
 * @param type The type of sensor to create ("Altitude" or "Velocity")
 * @param name The name/identifier for the sensor instance
 * @return unique_ptr to the newly created sensor
 * @throws std::invalid_argument if type is not recognized
 */
std::unique_ptr<Sensor> createSensor(const std::string& type, const std::string& name) {
	if (type == "Altitude") return std::make_unique<AltitudeSensor>(name);
	if (type == "Velocity") return std::make_unique<VelocitySensor>(name);

	// Throw exception for invalid sensor type
	throw std::invalid_argument("Unknown Sensor Type: " + type);
}