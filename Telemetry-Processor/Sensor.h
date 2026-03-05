#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <memory>
#include <random>

// Common interface for all sensor types.
class Sensor {
public:
	// Initializes sensor name and RNG.
	explicit Sensor(std::string name);

	// Virtual for safe polymorphic destruction.
	virtual ~Sensor() = default;

	// Generates one simulated reading.
	virtual double readData() = 0;

	// Returns sensor type label.
	virtual std::string getType() const = 0;

	// Returns sensor name.
	std::string getName() const;

	// Basic validity check for readings.
	bool isValid(double value) const;

protected:
	std::string name_;
	std::mt19937 rng_;
};

// Simulates altitude in feet.
class AltitudeSensor : public Sensor {
public:
	explicit AltitudeSensor(std::string name = "Altitude");
	double readData() override;
	std::string getType() const override;
};

// Simulates velocity in knots.
class VelocitySensor : public Sensor {
public:
	explicit VelocitySensor(std::string name = "Airspeed");
	double readData() override;
	std::string getType() const override;
};

#endif