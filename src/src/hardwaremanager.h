#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"

class HardwareManager {
private:
    InfraredSensorArray irArray;
public:
    HardwareManager();
    bool isLeftWall() const;
    bool isCenterWall() const;
    bool isRightWall() const;
};

#endif // HARDWAREMANAGER_H
