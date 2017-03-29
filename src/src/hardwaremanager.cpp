#include <Arduino.h>
#include <mk20dx128.h>

#include "encoders.h"
#include "hardwaremanager.h"

HardwareManager::HardwareManager() {

}

bool HardwareManager::isLeftWall() const {
    return irArray.getLeftDistance() > 8000;
}

bool HardwareManager::isCenterWall() const {
    return irArray.getCenterDistance() > 8000;
}

bool HardwareManager::isRightWall() const {
    return irArray.getRightDistance() > 8000;
}

DifferentialDriveVelcity HardwareManager::convertDifferentialDrive(const int forwardVelocity, const double angularVelocity) const {
    int linearVelocity = forwardVelocity / radius;
    double rotationalVelocity = (angularVelocity * wheelbase) / (2 * radius);

    int leftV  = linearVelocity - rotationalVelocity;
    int rightV = linearVelocity + rotationalVelocity;

    return DifferentialDriveVelcity(leftV, rightV);
}

void HardwareManager::drive(const int distInMM, const double angleInRadians) {
    // TODO This can be simplified with sentinal values in angle/dist controllers
    // Also if we have traveled the correct number of degrees/mm, changing the set point to 0 will cause the function to return


#warning implement this
    //Encoders::getEncoders().reset();

    if (distInMM == 0 && angleInRadians == 0) {
        return;
    } else if (distInMM == 0) {
        while (true) {
            delay(1);
            if (getAngleTraveled() >= angleInRadians) {
                return;
            }
            const double omega = angleController(angleInRadians);
            const DifferentialDriveVelcity velocities = convertDifferentialDrive(0, omega);
            motorController(velocities);
        }
    } else if (angleInRadians == 0) {
        while (true) {
            delay(1);
            if (getDistanceTraveled() >= distInMM) {
                return;
            }
            const double omega = wallController();
            const int forwardVelocity = distanceController(distInMM);
            const DifferentialDriveVelcity velocities = convertDifferentialDrive(forwardVelocity, omega);
            motorController(velocities);
        }
    } else {
        while (true) {
            delay(1);
            if (getDistanceTraveled() >= distInMM && getAngleTraveled() >= angleInRadians) {
                return;
            }
            const double omega = angleController(angleInRadians) + wallController();
            const int forwardVelocity = distanceController(distInMM);
            const DifferentialDriveVelcity velocities = convertDifferentialDrive(forwardVelocity, omega);
            motorController(velocities);
        }
    }
}

int HardwareManager::getDistanceTraveled() {

}

double HardwareManager::getAngleTraveled() {

}

double HardwareManager::angleController(const double angleInRadians) {

}

double HardwareManager::wallController() {

}

int HardwareManager::distanceController(const int distanceInMM) {

}

void HardwareManager::motorController(const DifferentialDriveVelcity velocities) {

}
