#ifndef SENSOR_SIMULATOR_H
#define SENSOR_SIMULATOR_H

#include <string>

struct VitalSigns
{
    int heartRate;
    int spo2;
    int respirationRate;
    int bloodPressureSystolic;
    int bloodPressureDiastolic;
    std::string bloodPressure;
    std::string timestamp;
    std::string iso_timestamp;
};

struct SensorSimulator
{
    VitalSigns readVitals();
};

std::string iso_timestamp();

#endif