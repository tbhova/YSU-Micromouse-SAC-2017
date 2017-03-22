#ifndef BUILD_FOR_PC

#include "motors.h"

Motors::Motors() {
    this->coast();
}

void Motors::disengage() {
    digitalWriteFast(MOTOR_STANDBY, LOW);
}

void Motors::coast() {

}

void Motors::brake() {

}

void Motors::setSpeed(short int speedLeft, short int speedRight) {
    digitalWriteFast(MOTOR_STANDBY, HIGH);
    leftMotor.setSpeed(speedLeft);
    rightMotor.setSpeed(speedRight);
}

#endif // BUILD_FOR_PC
