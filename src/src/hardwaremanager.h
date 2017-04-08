#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include "infraredsensorarray.h"
#include "encoders.h"
#include "motors.h"
#include "abstracthardwaremanager.h"
#include "differentialdrivevelocity.h"

#include "wallcontroller.h"
#include "angledistancecontroller.h"
#include "motorcontroller.h"

class HardwareManager : public AbstractHardwareManager {
private:

public:
    HardwareManager();
    virtual ~HardwareManager() {}

    virtual bool isLeftWall() const;
    virtual bool isCenterWall() const;
    virtual bool isRightWall() const;

    bool isLeftDetected() const;
    bool isRightDetected() const;

    virtual void drive(const int distInMM, const double angleInRadians);

    /**
     * @brief convertDifferentialDrive - convert unicycle model (Velocity, omega) -> (leftWheelVelocity, RightWheelVelcity) differential drive model
     * @param forwardVelocity overall robot velocity in mm/second
     * @param angularVelcity turning speed of robot in radians/sec
     * @return differential drive left and right wheel velocities
     */
    DifferentialDriveVelcity convertDifferentialDrive(const int forwardVelocity, const double angularVelcity) const;

    void updateEncoders() {
        encoders.getLeftSpeed();
        encoders.getRightSpeed();
    }

    bool isRightWallAddWalls() const { return irArray.getRightDistance() < 168; }
    bool isLeftWallAddWalls() const { return irArray.getLeftDistance() < 168; }

private:
    InfraredSensorArray irArray;
    const int radius = 39/2, wheelbase = 89, ticksPerMM = 25, maxSpeed = 5900;
    int checkpointedLeftEncoder = 0, checkpointedRightEncoder = 0;


    int getDistanceTraveled();
    double getAngleTraveled();
    double angleController(const double angleInRadians);
    double wallController();
    int distanceController(const int distanceInMM);
    void motorController(const DifferentialDriveVelcity velocities);
    void resetMotorController();
    void checkpointEncoders();
    void checkpointWalls();

    bool isLeftWallRightNow() const;
    bool isCenterWallRightNow() const;
    bool isRightWallRightNow() const;

    int lastLeftWallDistance = 0, lastRightWallDistance = 0;

    bool leftWall = false, rightWall = false;

    Encoders encoders;
    Motors motors;
    WallController wallPID;
    AngleDistanceController angleDistController;
    MotorController leftMotorPID;
    MotorController rightMotorPID;

};

#endif // HARDWAREMANAGER_H
