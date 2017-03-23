#include "motors.h"

Motors::Motors() {
    disengage();
}

void Motors::disengage() {
    digitalWriteFast(MOTOR_STANDBY, LOW);
}

void Motors::coast() {
    digitalWriteFast(MOTOR_STANDBY, HIGH);
    leftMotor.coast();
    rightMotor.coast();
}

void Motors::brake() {
    digitalWriteFast(MOTOR_STANDBY, HIGH);
    leftMotor.brake();
    rightMotor.brake();
}

void Motors::setSpeed(short int speedLeft, short int speedRight) {
    digitalWriteFast(MOTOR_STANDBY, HIGH);
    leftMotor.setSpeed(speedLeft);
    rightMotor.setSpeed(speedRight);
}
