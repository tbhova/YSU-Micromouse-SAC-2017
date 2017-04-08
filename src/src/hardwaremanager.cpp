#include <Arduino.h>
#include <mk20dx128.h>

#include "encoders.h"
#include "hardwaremanager.h"

HardwareManager::HardwareManager() {

}

bool HardwareManager::isLeftWallRightNow() const {
    return irArray.getLeftDistance() < 125;
}

bool HardwareManager::isLeftWall() const {
//    return !leftWall;
    return isLeftWallRightNow();
}

bool HardwareManager::isCenterWallRightNow() const {
    return irArray.getCenterDistance() < 115;
}

bool HardwareManager::isCenterWall() const {
    return isCenterWallRightNow();
}

bool HardwareManager::isRightWallRightNow() const {
    return irArray.getRightDistance() < 125;
}

bool HardwareManager::isRightWall() const {
    //return !rightWall;
    return isRightWallRightNow();
}

bool HardwareManager::isLeftDetected() const {
//    return irArray.getLeftDistance() < 70;
    return leftWall;
}

bool HardwareManager::isRightDetected() const {
//    return irArray.getRightDistance() < 70;
    return rightWall;
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

//    encoders.reset(0);
//    wallPID.reset();
//    resetMotorController();
    this->checkpointEncoders();

    leftWall = false;
    rightWall = false;
    bool wallsChecked = false;

    if (distInMM == 0 && angleInRadians == 0) {
        return;
    } else if (distInMM == 0) {
        const int ticks = millis();
        int lastTicks = millis();
        while (millis() - ticks < 300) {
            if (millis() != lastTicks) {
                encoders.getLeftSpeed();
                encoders.getRightSpeed();
                lastTicks = millis();
            }
        }
        while (true) {
            delay(1);
            if (abs(getAngleTraveled()) >= abs(angleInRadians)) {
                motors.coast();
                return;
            }
            const double omega = angleController(angleInRadians);
            const DifferentialDriveVelcity velocities = convertDifferentialDrive(0, omega);
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
    } else if (angleInRadians == 0) {
        while (true) {
            delay(1);
            if (abs(getDistanceTraveled()) >= abs(distInMM)) {
                motors.coast();
                if (isCenterWallRightNow()) {
                    const int originalDistance = irArray.getCenterDistance();
                    DifferentialDriveVelcity calVelocity = DifferentialDriveVelcity(-45, -45);

                    checkpointEncoders();
                    while (abs(getDistanceTraveled()) < 10) {
                        motorController(calVelocity);
                        delay(1);
                    }
                    motors.coast();

                    const int newDistance = irArray.getCenterDistance();
                    const int distanceToDrive = newDistance - 46;
                    if (newDistance >= originalDistance) {
                        calVelocity.left *= -1;
                        calVelocity.right *= -1;
                    }

                    checkpointEncoders();
                    while (abs(getDistanceTraveled()) < abs(distanceToDrive)) {
                        motorController(calVelocity);
//                        motors.setSpeed(calVelocity.left, calVelocity.right);
                        delay(1);
                    }
                }

                motors.coast();
                return;
            }
            if (!wallsChecked && distInMM == 180 && getDistanceTraveled() > 55) {
                wallsChecked = true;
                leftWall = isLeftWallAddWalls();
                rightWall = isRightWallAddWalls();
            }
            const double omega = wallController();
//            checkpointWalls();
            const int forwardVelocity = distanceController(distInMM);
#warning remove
//            Serial.print(omega);
//            Serial.print("   ");
//            Serial.print(forwardVelocity);
//            Serial.println(" ");
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
                motors.coast();
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
    const int leftDistance = encoders.getLeftTicks() - checkpointedLeftEncoder;
    const int rightDistance = encoders.getRightTicks() - checkpointedRightEncoder;

    return (leftDistance + rightDistance) / (2 * ticksPerMM);
}

double HardwareManager::getAngleTraveled() {
    const int leftDistance = encoders.getLeftTicks() - checkpointedLeftEncoder;
    const int rightDistance = encoders.getRightTicks() - checkpointedRightEncoder;

    return static_cast<double>(rightDistance - leftDistance) / static_cast<double>(wheelbase * ticksPerMM);
}

double HardwareManager::angleController(const double angleInRadians) {
    return angleDistController.getNewOmega(getAngleTraveled(), angleInRadians);
}

double HardwareManager::wallController() {
#warning remove
    /*Serial.print("IR   ");
    Serial.print(irArray.getLeftDistance());
    Serial.print(" ");
    Serial.print(irArray.getRightDistance());
    Serial.println(" ");*/
    return wallPID.getNewOmega(irArray.getLeftDistance(), irArray.getRightDistance(), !isCenterWall() && isLeftWallRightNow(), !isCenterWall() && isRightWallRightNow());
}

int HardwareManager::distanceController(const int distanceInMM) {
    return angleDistController.getNewVelocity(getDistanceTraveled(), distanceInMM);
}

void HardwareManager::motorController(const DifferentialDriveVelcity velocities) {
    int leftSpeed = leftMotorPID.getPWM(velocities.left, encoders.getLeftSpeed()/ticksPerMM);
    int rightSpeed = rightMotorPID.getPWM(velocities.right, encoders.getRightSpeed()/ticksPerMM);
    motors.setSpeed(leftSpeed, rightSpeed);
}

void HardwareManager::resetMotorController(){
    leftMotorPID.reset();
    rightMotorPID.reset();
}

void HardwareManager::checkpointEncoders() {
    checkpointedLeftEncoder = encoders.getLeftTicks();
    checkpointedRightEncoder = encoders.getRightTicks();
}

void HardwareManager::checkpointWalls() {
    const int distance = getDistanceTraveled();

    if (isLeftWallRightNow()) {
        lastLeftWallDistance = distance;
    }
    if (isRightWallRightNow()) {
        lastRightWallDistance = distance;
    }

    // only able to set wall after we've traveled 6 cm
    leftWall = leftWall || distance - lastLeftWallDistance > 60;
    rightWall = rightWall || distance - lastRightWallDistance > 60;
}
