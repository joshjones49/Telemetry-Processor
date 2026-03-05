#include <gtest/gtest.h>
#include "../../Sensor.h"

// Basic construction checks.
TEST(SensorSimpleTests, CanCreateAltitudeSensor) {
	AltitudeSensor sensor("sensor1");
	SUCCEED();
}

TEST(SensorSimpleTests, CanCreateVelocitySensor) {
	VelocitySensor sensor("sensor1");
	SUCCEED();
}

TEST(SensorSimpleTests, CanCreateMultipleSensor) {
	VelocitySensor velSensor1("vel sensor1");
	VelocitySensor velSensor2("vel sensor2");

	AltitudeSensor altSensor1("alt sensor1");
	AltitudeSensor altSensor2("alt sensor2");
	SUCCEED();
}

TEST(SensorSimpleTests, CanGetName) {
	AltitudeSensor alt("sensor1");
	VelocitySensor vel("sensor2");

	EXPECT_NO_THROW({
		alt.getName();
		vel.getName();
	});
}

TEST(SensorSimpleTests, CanGetAltAndVel) {
	AltitudeSensor alt("sensor1");
	VelocitySensor vel("sensor2");

	EXPECT_NO_THROW({
		alt.readData();
		vel.readData();
	});
}