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

    std::uniform_int_distribution<> hr(50, 120);
    std::uniform_int_distribution<> spo2(85, 100);
    std::uniform_int_distribution<> resp(8, 25);
    std::uniform_int_distribution<> bp_systolic(80, 190);

    VitalSigns v;
    v.heartRate = hr(gen);
    v.spo2 = spo2(gen);
    v.respirationRate = resp(gen);
    v.bloodPressureSystolic = bp_systolic(gen);
    std::uniform_int_distribution<> bp_diastolic(50, v.bloodPressureSystolic - 1); // ensure the diastolic pressure is < the systolic pressure
    v.bloodPressureDiastolic = bp_diastolic(gen);
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