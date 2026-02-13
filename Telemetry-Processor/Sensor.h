#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <memory> // used for memory management (unique_ptr, shared_ptr, weak_ptr)
#include <random>

/**
 * Sensor (Abstract Base Class) - Represents a generic telemetry sensor
 * 
 * Defines the interface that all concrete sensor types must implement.
 * Uses polymorphism to allow different sensor types to be treated uniformly.
 * Includes random number generation for simulating realistic sensor readings.
 */
class Sensor {
public:
	/**
	 * Constructor - initializes sensor with a name and sets up RNG
	 * @param name Unique identifier for this sensor instance
	 */
	explicit Sensor(std::string name);

	// Virtual destructor ensures proper cleanup in derived classes
	virtual ~Sensor() = default;

	/**
	 * Pure virtual - derived classes must implement sensor-specific reading logic
	 * @return Simulated sensor reading value
	 */
	virtual double readData() = 0;

	/**
	 * Pure virtual - returns the type of sensor (e.g., "Altitude", "Velocity")
	 * @return String identifier for sensor type
	 */
	virtual std::string getType() const = 0;

	/**
	 * Returns the sensor's name/identifier
	 * @return Sensor name string
	 */
	std::string getName() const;

	/**
	 * Validates if a sensor reading is within acceptable bounds
	 * @param value The reading to validate
	 * @return true if valid, false otherwise
	 */
	bool isValid(double value) const;

protected:
	std::string name_;      // Sensor identifier (e.g., "Altimeter-1")
	std::mt19937 rng_;      // Mersenne Twister random number generator for simulations
};

/**
 * AltitudeSensor - simulates altitude readings in feet
 * 
 * Generates readings with a normal distribution centered around 20,000 ft
 * with standard deviation of 300 ft (simulates realistic variation)
 */
class AltitudeSensor : public Sensor {
public:
	explicit AltitudeSensor(std::string name = "Altitude");
	double readData() override;           // Returns simulated altitude (0-40k ft)
	std::string getType() const override; // Returns "Altitude"
};

/**
 * VelocitySensor - simulates velocity/airspeed readings in knots
 * 
 * Generates readings uniformly distributed between 200-600 knots
 * (typical range for commercial/military aircraft)
 */
class VelocitySensor : public Sensor {
public:
	explicit VelocitySensor(std::string name = "Airspeed");
	double readData() override;           // Returns simulated velocity (200-600 knots)
	std::string getType() const override; // Returns "Velocity"
};

#endif