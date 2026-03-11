#include "SensorSimulator.h"

#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

VitalSigns SensorSimulator::readVitals() // Returns VitalSigns struct; member function of SensorSimulator struct; named readVitals;
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Base vitals with normal ranges
    int baseHeartRate = 70;
    int baseSpo2 = 98;
    int baseRespirationRate = 16;
    int baseBloodPressureSystolic = 120;
    int baseBloodPressureDiastolic = 70;

    // Vital ranges
    const int HR_MAX = 120;
    const int HR_MIN = 50;
    const int SPO2_MAX = 100;
    const int SPO2_MIN = 90;
    const int RESP_MAX = 25;
    const int RESP_MIN = 10;
    const int BP_SYSTOLIC_MAX = 180;
    const int BP_SYSTOLIC_MIN = 90;
    const int BP_DIASTOLIC_MAX = 120;
    const int BP_DIASTOLIC_MIN = 60;

    // Add some variability to the vitals each second
    std::uniform_int_distribution<> hr(-4, 4);
    std::uniform_int_distribution<> spo2(-1, 1);
    std::uniform_int_distribution<> resp(-3, 3);
    std::uniform_int_distribution<> bp_systolic(0, 10);
    std::uniform_int_distribution<> bp_diastolic(-10, 10);

    // Don't let the vitals go out of realistic bounds
    if (baseHeartRate + hr(gen) > HR_MAX)
        baseHeartRate = HR_MAX;
    else if (baseHeartRate + hr(gen) < HR_MIN)
        baseHeartRate = HR_MIN;
    else
        baseHeartRate += hr(gen);

    if (baseSpo2 + spo2(gen) > SPO2_MAX)
        baseSpo2 = SPO2_MAX;
    else if (baseSpo2 + spo2(gen) < SPO2_MIN)
        baseSpo2 = SPO2_MIN;
    else

        baseSpo2 += spo2(gen);
    if (baseRespirationRate + resp(gen) > RESP_MAX)
        baseRespirationRate = RESP_MAX;
    else if (baseRespirationRate + resp(gen) < RESP_MIN)
        baseRespirationRate = RESP_MIN;
    else
        baseRespirationRate += resp(gen);

    if (baseBloodPressureSystolic + bp_systolic(gen) > BP_SYSTOLIC_MAX)
        baseBloodPressureSystolic = BP_SYSTOLIC_MAX;
    else if (baseBloodPressureSystolic + bp_systolic(gen) < BP_SYSTOLIC_MIN)
        baseBloodPressureSystolic = BP_SYSTOLIC_MIN;
    else
        baseBloodPressureSystolic += bp_systolic(gen);

    if (baseBloodPressureDiastolic + bp_diastolic(gen) > BP_DIASTOLIC_MAX)
        baseBloodPressureDiastolic = BP_DIASTOLIC_MAX;
    else if (baseBloodPressureDiastolic + bp_diastolic(gen) < BP_DIASTOLIC_MIN)
        baseBloodPressureDiastolic = BP_DIASTOLIC_MIN;
    else
        baseBloodPressureDiastolic += bp_diastolic(gen);

    // Create a VitalSigns struct give it the generated vitals
    VitalSigns v;
    v.heartRate = baseHeartRate;
    v.spo2 = baseSpo2;
    v.respirationRate = baseRespirationRate;
    v.bloodPressureSystolic = baseBloodPressureSystolic;
    v.bloodPressureDiastolic = baseBloodPressureDiastolic;

    v.bloodPressure = std::to_string(v.bloodPressureSystolic) + " / " + std::to_string(v.bloodPressureDiastolic);

    time_t now = time(0);
    v.timestamp = ctime(&now);
    v.iso_timestamp = iso_timestamp();

    return v;
}

std::string iso_timestamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm *ltm = std::localtime(&now_c);

    std::stringstream ss;
    ss << std::put_time(ltm, "%Y-%m-%d %H:%M:%S");

    return ss.str();
}