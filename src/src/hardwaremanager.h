#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"
#include "abstracthardwaremanager.h"

class HardwareManager : public AbstractHardwareManager {
private:
    InfraredSensorArray irArray;
public:
    HardwareManager();
    virtual ~HardwareManager() {}
    virtual bool isLeftWall() const;
    virtual bool isCenterWall() const;
    virtual bool isRightWall() const;
};

#endif // HARDWAREMANAGER_H
