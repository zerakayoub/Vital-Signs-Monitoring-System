#include "DataLogger.h"
#include <fstream>

void DataLogger::log(const VitalSigns &v, const VitalAnalyzer &analysis) // takes const reference to VitalSigns struct as parameter;
{
    std::ofstream file("vitals_log.csv", std::ios::app);

    // Log the vitals to the csv file
    file << "\n"
         << v.timestamp
         << "Heart Rate: " << v.heartRate << ", " << analysis.getHeartRateStatus() << "\n"
         << "SpO2: " << v.spo2 << ", " << analysis.getSpo2Status() << "\n"
         << "Respiration Rate: " << v.respirationRate << ", " << analysis.getRespirationRateStatus() << "\n"
         << "Blood Pressure: " << v.bloodPressure << ", " << analysis.getBloodPressureStatus() << "\n";
}