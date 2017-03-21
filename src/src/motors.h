#ifndef BUILD_FOR_PC
#ifndef MOTORS_H
#define MOTORS_H


class Motors {

public:
    Motors();

private:
    class Motor {
    public:
        Motor();
    };

    Motor leftMotor, rightMotor;
};

#endif // MOTORS_H
#endif // BUILD_FOR_PC
