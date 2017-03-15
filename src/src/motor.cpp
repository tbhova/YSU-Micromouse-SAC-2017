#include "motors.h"

//Motors::Motor() {

//}

void Motors::Motor::setSpeed(short int speed) {
    analogWrite(speedPin, speed);
}
