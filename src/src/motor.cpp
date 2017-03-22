#ifndef BUILD_FOR_PC

#include "motors.h"

Motors::Motor::Motor(int forward, int reverse, int speed) {
    this->forwardPin = forward;
    this->reversePin = reverse;
    this->speedPin = speed;
}

void Motors::Motor::setSpeed(short int speed) {
    if (speed<=0) {
       digitalWriteFast(reversePin, HIGH);
       digitalWriteFast(forwardPin, LOW);
    }
    else if (speed>=0) {
        digitalWriteFast(reversePin, LOW);
        digitalWriteFast(forwardPin, HIGH);
    }

    analogWrite(speedPin, abs(speed));
}

#endif // BUILD_FOR_PC
