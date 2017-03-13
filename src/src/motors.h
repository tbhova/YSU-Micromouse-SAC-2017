#ifndef MOTORS_H
#define MOTORS_H

#include "pins.h"

class Motors {

public:
    Motors();

private:
    class Motor {
    public:
        Motor();

    };

    void rightForward();
    void rightStop();
    void rightReverse();
    void leftForward();
    void leftStop();
    void leftReverse();
    void stop();
    void driveForward();
    void turn();
    const int power = 127, off = 0;

    Motor leftMotor, rightMotor;
};

#endif // MOTORS_H
