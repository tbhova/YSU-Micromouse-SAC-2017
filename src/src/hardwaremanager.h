#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"

class HardwareManager {
private:
    InfraredSensorArray irArray;
public:
    bool* areWalls();



};

#endif // HARDWAREMANAGER_H
