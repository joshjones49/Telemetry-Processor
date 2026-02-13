#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <memory>
#include <random>

class Sensor {
public:
	explicit Sensor(std::string name);
	virtual ~Sensor() = default;

	virtual double readData() = 0;
	virtual std::string getType() const = 0;
	std::string getName() const;

	bool isValid(double value) const;

protected:
	std::string name_;
	std::mt19937 rng_;
};

#endif