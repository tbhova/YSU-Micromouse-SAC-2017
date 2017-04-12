#include "motors.h"

Motors::Motors() {
    disengage();
}

void Motors::disengage() {
    setSpeed(0,0);
    digitalWriteFast(MOTOR_STANDBY, LOW);
}

void Motors::setSpeed(short int speedLeft, short int speedRight) {
    digitalWriteFast(MOTOR_STANDBY, HIGH);
    leftMotor.setSpeed(speedLeft);
    rightMotor.setSpeed(speedRight);
}

void Motors::brake() {
    setSpeed(0,0);
    leftMotor.brake();
    rightMotor.brake();
    digitalWriteFast(MOTOR_STANDBY, HIGH);
}

void Motors::coast() {
    setSpeed(0,0);
    leftMotor.coast();
    rightMotor.coast();
    digitalWriteFast(MOTOR_STANDBY, LOW);
}
