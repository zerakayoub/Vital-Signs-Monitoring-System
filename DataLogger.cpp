#include "DataLogger.h"
#include <fstream>

void DataLogger::log(const VitalSigns &v, const VitalAnalyzer &analysis) // takes const reference to VitalSigns struct as parameter;
{
    std::ofstream human_readable_file("vitals_log.csv", std::ios::app);
    std::ofstream machine_readable_file("machine_vitals_log.csv", std::ios::app);

    // Log the vitals to the csv file
    human_readable_file << "\n"
                        << v.timestamp
                        << "Heart Rate: " << v.heartRate << ", " << analysis.getHeartRateStatus() << "\n"
                        << "SpO2: " << v.spo2 << ", " << analysis.getSpo2Status() << "\n"
                        << "Respiration Rate: " << v.respirationRate << ", " << analysis.getRespirationRateStatus() << "\n"
                        << "Blood Pressure: " << v.bloodPressure << ", " << analysis.getBloodPressureStatus() << "\n";

    machine_readable_file << v.iso_timestamp << ","
                          << v.heartRate << "," << analysis.getHeartRateStatus() << ","
                          << v.spo2 << "," << analysis.getSpo2Status() << ","
                          << v.respirationRate << "," << analysis.getRespirationRateStatus() << ","
                          << v.bloodPressureSystolic << "," << v.bloodPressureDiastolic << "," << analysis.getBloodPressureStatus() << "\n";
}
