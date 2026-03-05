#include <gtest/gtest.h>
#include "../../Telemetry-Processor.h"
#include "../../Sensor.h"

// Basic processor construction and setup.
TEST(ProcessorSimpleTest, CanCreateProcessor) {
	TelemetryProcessor processor();

	SUCCEED();
}

TEST(ProcessorSimpleTest, CanCreateMultiple) {
	TelemetryProcessor p1;
	TelemetryProcessor p2;
	TelemetryProcessor p3;

	SUCCEED();
}

TEST(ProcessorSimpleTest, CanAddSensors) {
	TelemetryProcessor p1;

	EXPECT_NO_THROW({
		p1.addSensor(std::make_unique<AltitudeSensor>("sensor1"));
	});
}