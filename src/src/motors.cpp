#include "motors.h"
#include "mk20dx128.h"
#include "Arduino.h"
#include "pins.h"

Motors::Motors()
{
    this->stop();
}

void Motors::driveForward() {
    leftForward();
    rightForward();
}

void Motors::turn() {
    rightForward();
    leftReverse();
}

void Motors::stop() {
    rightStop();
    leftStop();
}

void Motors::leftForward() {
    digitalWriteFast(LEFT_MOTOR_REVERSE, LOW);
    digitalWriteFast(LEFT_MOTOR_FORWARD, HIGH);
    analogWrite(LEFT_MOTOR_SPEED, power);
}

void Motors::leftStop() {
    digitalWriteFast(LEFT_MOTOR_FORWARD, LOW);
    digitalWriteFast(LEFT_MOTOR_REVERSE, LOW);
    analogWrite(LEFT_MOTOR_SPEED, off);
}

void Motors::leftReverse() {
    digitalWriteFast(LEFT_MOTOR_FORWARD, LOW);
    digitalWriteFast(LEFT_MOTOR_REVERSE, HIGH);
    analogWrite(LEFT_MOTOR_SPEED, power);
}

void Motors::rightForward() {
    digitalWriteFast(RIGHT_MOTOR_REVERSE, LOW);
    digitalWriteFast(RIGHT_MOTOR_FORWARD, HIGH);
    analogWrite(RIGHT_MOTOR_SPEED, power);
}

void Motors::rightReverse() {
    digitalWriteFast(RIGHT_MOTOR_FORWARD, LOW);
    digitalWriteFast(RIGHT_MOTOR_REVERSE, HIGH);
    analogWrite(RIGHT_MOTOR_SPEED, power);
}

void Motors::rightStop() {
    digitalWriteFast(RIGHT_MOTOR_REVERSE, LOW);
    digitalWriteFast(RIGHT_MOTOR_FORWARD, LOW);
    analogWrite(RIGHT_MOTOR_SPEED, off);
}
