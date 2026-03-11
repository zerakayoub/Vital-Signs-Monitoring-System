#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include "SensorSimulator.h"
#include "VitalAnalyzer.h"

struct DataLogger
{
    void log(const VitalSigns &vitals, const VitalAnalyzer &analysis);
};

#endif