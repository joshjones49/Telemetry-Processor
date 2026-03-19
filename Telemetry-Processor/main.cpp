#include "Telemetry-Processor.h"
#include "data.h"

#include <iostream>
#include<thread>

// Run a short telemetry simulation.
int main() {
    std::cout << "=== Simple Telemetry Processor ===\n\n";

    try {
        std::thread ArrowThread(createSensorsRunSim, "Arrow", std::ref(ArrowData));
        std::thread ShieldThread(createSensorsRunSim, "Shield", std::ref(ShieldData));
        std::thread SwordThread(createSensorsRunSim, "Sword", std::ref(SwordData));

        ArrowThread.join();
        ShieldThread.join();
        SwordThread.join();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\nSimulation finished.\n";

    return 0;
}