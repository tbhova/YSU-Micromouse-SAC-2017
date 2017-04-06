#include <Arduino.h>
#include <mk20dx128.h>

#include "encoders.h"
#include "hardwaremanager.h"

HardwareManager::HardwareManager() {

}

bool HardwareManager::isLeftWall() const {
    return irArray.getLeftDistance() < 170;
}

bool HardwareManager::isCenterWall() const {
    return irArray.getCenterDistance() < 170;
}

bool HardwareManager::isRightWall() const {
    return irArray.getRightDistance() < 170;
}

DifferentialDriveVelcity HardwareManager::convertDifferentialDrive(const int forwardVelocity, const double angularVelocity) const {
    const double rotationalVelocity = (angularVelocity * wheelbase) / 2;

    const int leftV  = forwardVelocity - rotationalVelocity;
    const int rightV = forwardVelocity + rotationalVelocity;

    return DifferentialDriveVelcity(leftV, rightV);
}

void HardwareManager::drive(const int distInMM, const double angleInRadians) {
    // TODO This can be simplified with sentinal values in angle/dist controllers
    // Also if we have traveled the correct number of degrees/mm, changing the set point to 0 will cause the function to return

#warning remove
    /*Serial.print("dist ");
    Serial.println(distInMM);
    Serial.print("angle ");
    Serial.println(angleInRadians);

    encoders.reset(0);
    wallPID.reset();
    resetMotorController();
    if (distInMM == 0 && angleInRadians == 0) {
        return;
    } else if (distInMM == 0) {
        while (true) {
            delay(1);
            if (abs(getAngleTraveled()) >= abs(angleInRadians)) {
                motors.coast();
                return;
            }
            const double omega = angleController(angleInRadians);
            const DifferentialDriveVelcity velocities = convertDifferentialDrive(0, omega);
            motorController(velocities);
        }
    } else if (angleInRadians == 0) {
        while (true) {
            delay(1);
            if (abs(getDistanceTraveled()) >= abs(distInMM)) {
                motors.coast();
                return;
            }
            const double omega = wallController();
            //const double omega = 0;
            const int forwardVelocity = distanceController(distInMM);
#warning remove
            /*Serial.print(omega);
            Serial.print("   ");
            Serial.print(forwardVelocity);
            Serial.println(" ");
//            Serial.print(forwardVelocity);*/
            const DifferentialDriveVelcity velocities = convertDifferentialDrive(forwardVelocity, omega);
#warning remove
//            Serial.print(" ");
//            Serial.print(velocities.left);
//            Serial.print(" ");
//            Serial.print(velocities.right);
//            Serial.print(" ");
//            Serial.print(encoders.getLeftSpeed()/ticksPerMM);
//            Serial.print(" ");
//            Serial.println(encoders.getRightSpeed()/ticksPerMM);
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
    const int leftDistance = encoders.getLeftTicks();
    const int rightDistance = encoders.getRightTicks();

    return (leftDistance + rightDistance) / (2 * ticksPerMM);
}

double HardwareManager::getAngleTraveled() {
    const int leftDistance = encoders.getLeftTicks();
    const int rightDistance = encoders.getRightTicks();

    return static_cast<double>(rightDistance - leftDistance) / static_cast<double>(wheelbase * ticksPerMM);
}

double HardwareManager::angleController(const double angleInRadians) {
    return angleDistController.getNewOmega(getAngleTraveled(), angleInRadians);
}

double HardwareManager::wallController() {
#warning remove
    Serial.print(irArray.getLeftDistance());
    Serial.print(" ");
    Serial.print(irArray.getRightDistance());
    Serial.print(" ");
    return wallPID.getNewOmega(irArray.getLeftDistance(), irArray.getRightDistance(), isLeftWall(), isRightWall());
}

int HardwareManager::distanceController(const int distanceInMM) {
    return angleDistController.getNewVelocity(getDistanceTraveled(), distanceInMM);
}

void HardwareManager::motorController(const DifferentialDriveVelcity velocities) {
    int leftSpeed = leftMotorPID.getPWM(velocities.left, encoders.getLeftSpeed()/ticksPerMM);
    int rightSpeed = rightMotorPID.getPWM(velocities.right, encoders.getRightSpeed()/ticksPerMM);
#warning remove
    /*Serial.print("Left/Right Speed:   ");
    Serial.print(encoders.getLeftSpeed());
    Serial.print(" , ");
    Serial.println(encoders.getRightSpeed());*/
    motors.setSpeed(leftSpeed, rightSpeed);
}
