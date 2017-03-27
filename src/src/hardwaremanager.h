#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"
#include "abstracthardwaremanager.h"
#include "differentialdrivevelocity.h"

class HardwareManager : public AbstractHardwareManager {
private:
    InfraredSensorArray irArray;
    const int radius = 390/2, wheelbase = 860;
public:
    HardwareManager();
    virtual ~HardwareManager() {}

    virtual bool isLeftWall() const;
    virtual bool isCenterWall() const;
    virtual bool isRightWall() const;

    DifferentialDriveVelcity convertDifferentialDrive(const int forwardVelocity, const double angularVelcity) const;
};

#endif // HARDWAREMANAGER_H
