#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <fstream>

#include "SensorSimulator.h"
#include "VitalAnalyzer.h"
#include "DataLogger.h"

int main()
{
    // Clear the log files and write the headers
    std::ofstream file("machine_vitals_log.csv");
    std::ofstream file2("vitals_log.csv");
    file << "timestamp,heart_rate,heart_rate_status,spo2,spo2_status,"
            "respiration,respiration_status,blood_pressure_systolic,blood_pressure_diastolic,blood_pressure_status\n";
    file.close();
    file2 << "VITALS LOG FILES\n";
    file2.close();

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