#include <iostream>
#include <thread>
#include <chrono>

#include "SensorSimulator.h"
#include "VitalAnalyzer.h"
#include "DataLogger.h"

int main()
{
    SensorSimulator sensor;
    VitalAnalyzer analyzer;
    DataLogger logger;

    while (true)
    {
        VitalSigns vitals = sensor.readVitals();

        analyzer.analyze(vitals);

        logger.log(vitals, analyzer);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}