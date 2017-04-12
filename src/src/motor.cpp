#include "motors.h"

Motors::Motor::Motor(const int forward, const int reverse, const int speed) {
    forwardPin = forward;
    reversePin = reverse;
    speedPin = speed;
}

void Motors::Motor::brake() {
    digitalWriteFast(forwardPin, HIGH);
    digitalWriteFast(reversePin, HIGH);
}

void Motors::Motor::coast() {
    digitalWriteFast(forwardPin, LOW);
    digitalWriteFast(reversePin, LOW);
}

void Motors::Motor::setSpeed(short int speed) {
    if (speed < 0) {
       digitalWriteFast(reversePin, HIGH);
       digitalWriteFast(forwardPin, LOW);
    } else {
        digitalWriteFast(reversePin, LOW);
        digitalWriteFast(forwardPin, HIGH);
    }

    analogWrite(speedPin, abs(speed));
}
