#include "hardwaremanager.h"

HardwareManager::HardwareManager() {

}

bool HardwareManager::isLeftWall() const {
    return irArray.getLeftIR() > 8000;
}

bool HardwareManager::isCenterWall() const {
    return irArray.getCenterIR() > 8000;
}

bool HardwareManager::isRightWall() const {
    return irArray.getRightIR() > 8000;
}

DifferentialDriveVelcity HardwareManager::convertDifferentialDrive(const int forwardVelocity, const double angularVelocity) const {
    int linearVelocity = forwardVelocity / radius;
    double rotationalVelocity = (angularVelocity * wheelbase) / (2 * radius);

    int leftV  = linearVelocity - rotationalVelocity;
    int rightV = linearVelocity + rotationalVelocity;

    return DifferentialDriveVelcity(leftV, rightV);
}
