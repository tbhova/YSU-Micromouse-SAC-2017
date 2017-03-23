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
    static void disengage();
    void setSpeed(const short int speedLeft, const short int speedRight);

private:
    class Motor {
    public:
        Motor(const int forward, const int reverse, const int speed);
        void setSpeed(const short int speed);
        void brake();
        void coast();
    private:
        int forwardPin, reversePin, speedPin;
    };

    Motor rightMotor = Motor(RIGHT_MOTOR_FORWARD, RIGHT_MOTOR_REVERSE, RIGHT_MOTOR_SPEED);
    Motor leftMotor = Motor(LEFT_MOTOR_FORWARD, LEFT_MOTOR_REVERSE, LEFT_MOTOR_SPEED);
};

#endif // MOTORS_H
