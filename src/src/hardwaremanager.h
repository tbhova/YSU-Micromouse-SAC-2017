#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"

class HardwareManager {
private:
    Driver driver;



public:
    HardwareManager();
    getIRData(InfraredSensor);
    short int* irData;
};

#endif // HARDWAREMANAGER_H
