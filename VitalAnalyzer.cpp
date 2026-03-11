#include "VitalAnalyzer.h"
#include <iostream>

void VitalAnalyzer::analyze(const VitalSigns &v)
{
    if (v.heartRate < 60)
    {
        std::cout << "WARNING: Low Heart Rate\n";
        heartRateStatus = "WARNING_LOW_HEART_RATE";
    }
    else if (v.heartRate > 100)
    {
        std::cout << "ALERT: High Heart Rate\n";
        heartRateStatus = "ALERT_HIGH_HEART_RATE";
    }
    else
    {
        heartRateStatus = "NORMAL";
    }
    if (v.spo2 < 95)
    {
        std::cout << "WARNING: Low Oxygen\n";
        spo2Status = "WARNING_LOW_OXYGEN";
    }
    else
    {
        spo2Status = "NORMAL";
    }

    if (v.respirationRate < 12 || v.respirationRate > 20)
    {
        std::cout << "WARNING: Abnormal Respiration\n";
        respirationRateStatus = "WARNING_ABNORMAL_RESPIRATION";
    }
    else
    {
        respirationRateStatus = "NORMAL";
    }

    if (v.bloodPressureSystolic >= 180 || v.bloodPressureDiastolic >= 120)
    {
        std::cout << "ALERT: Hypertensive Crisis\n";
        bloodPressureStatus = "ALERT_HYPERTENSIVE_CRISIS";
    }

    else if (v.bloodPressureSystolic > 140 || v.bloodPressureDiastolic > 80)
    {
        std::cout << "WARNING: Elevated Blood Pressure\n";
        bloodPressureStatus = "WARNING_ELEVATED_BLOOD_PRESSURE";
    }

    else if (v.bloodPressureSystolic < 90 || v.bloodPressureDiastolic < 60)
    {
        std::cout << "ALERT: Low Blood Pressure\n";
        bloodPressureStatus = "ALERT_LOW_BLOOD_PRESSURE";
    }
    else
    {
        bloodPressureStatus = "NORMAL";
    }
}