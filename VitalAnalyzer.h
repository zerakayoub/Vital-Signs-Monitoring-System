#ifndef VITAL_ANALYZER_H
#define VITAL_ANALYZER_H

#include "SensorSimulator.h"

struct VitalAnalyzer
{
    std::string heartRateStatus;
    std::string spo2Status;
    std::string respirationRateStatus;
    std::string bloodPressureStatus;
    std::string getHeartRateStatus() const { return heartRateStatus; }
    std::string getSpo2Status() const { return spo2Status; }
    std::string getRespirationRateStatus() const { return respirationRateStatus; }
    std::string getBloodPressureStatus() const { return bloodPressureStatus; }
    void analyze(const VitalSigns &vitals);
};

#endif