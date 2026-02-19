#include <gtest/gtest.h>
#include "../../Sensor.h"

// TEST 1 - Can we create an Altitude Sensor?
TEST(SensorSimpleTests, CanCreateAltitudeSensor) {
	// create sensor
	AltitudeSensor sensor("sensor1");
	// marks test as successful
	SUCCEED();
}

// Test 2 - Can we create a Velocity Sensor?
TEST(SensorSimpleTests, CanCreateVelocitySensor) {
	// create sensor
	VelocitySensor sensor("sensor1");
	// marks test as successful
	SUCCEED();
}

// TEST 3 - Can we create multiple sensors at the same time?
TEST(SensorSimpleTests, CanCreateMultipleSensor) {
	// create sensors
	VelocitySensor velSensor1("vel sensor1");
	VelocitySensor velSensor2("vel sensor2");

	AltitudeSensor altSensor1("alt sensor1");
	AltitudeSensor altSensor2("alt sensor2");
	// marks test as successful
	SUCCEED();
}

// TEST 4 - Can we read the sensors names?
TEST(SensorSimpleTests, CanGetName) {
	// create sensors
	AltitudeSensor alt("sensor1");
	VelocitySensor vel("sensor2");

	EXPECT_NO_THROW({
		alt.getName();
		vel.getName();
	});
}

// TEST 5 - Can we altitude/velocity of sensor?
TEST(SensorSimpleTests, CanGetAltAndVel) {
	// create sensors
	AltitudeSensor alt("sensor1");
	VelocitySensor vel("sensor2");

	EXPECT_NO_THROW({
		alt.readData();
		vel.readData();
	});
}