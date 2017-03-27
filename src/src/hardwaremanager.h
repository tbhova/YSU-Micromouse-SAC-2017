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

    /**
     * @brief convertDifferentialDrive - convert unicycle model (Velocity, omega) -> (leftWheelVelocity, RightWheelVelcity) differential drive model
     * @param forwardVelocity overall robot velocity in mm/second
     * @param angularVelcity turning speed of robot in radians/sec
     * @return differential drive left and right wheel velocities
     */
    DifferentialDriveVelcity convertDifferentialDrive(const int forwardVelocity, const double angularVelcity) const;
};

#endif // HARDWAREMANAGER_H
