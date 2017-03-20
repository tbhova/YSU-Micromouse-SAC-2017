#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"

class HardwareManager {
private:
    InfraredSensorArray irArray;
public:
    HardwareManager();
//    bool* areWalls();
    bool isLeftWall();
    bool isCenterWall();
    bool isRightWall();
};

#endif // HARDWAREMANAGER_H
