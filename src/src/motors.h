#ifndef MOTORS_H
#define MOTORS_H

#include "pins.h"
#include "mk20dx128.h"
#include "Arduino.h"

class Motors {

public:
    Motors();
    void brake();
    void coast();
    void disengage();
    void setSpeed(short int speedLeft, short int speedRight);

private:
    class Motor {
    public:
        Motor(int forward, int reverse, int speed);
        void setSpeed(short int);
        void brake();
        void coast();
    private:
        int forwardPin;
        int reversePin;
        int speedPin;
    };

    Motor rightMotor=(Motor(RIGHT_MOTOR_FORWARD,RIGHT_MOTOR_REVERSE,RIGHT_MOTOR_SPEED));
    Motor leftMotor=(Motor(LEFT_MOTOR_FORWARD,LEFT_MOTOR_REVERSE,LEFT_MOTOR_SPEED));
};

#endif // MOTORS_H
