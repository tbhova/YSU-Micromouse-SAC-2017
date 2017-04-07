#ifndef ENCODERS_H
#define ENCODERS_H
#include <Encoder.h>
#include "pins.h"

class Encoders {

public:
    Encoders();
    void reset(int reset);
    int getLeftSpeed();
    int getRightSpeed();
    int getLeftTicks();
    int getRightTicks();

private:
    class MouseEncoder {
    public:
        MouseEncoder(const int encoderA, const int encoderB);
        ~MouseEncoder();
        void reset(int reset);
        int getSpeed();
        int getTicks();

    private:
        Encoder* encoder;
        const double kp = 4.0, ki = 30.0, kd = 0.5;
        double positionEstimate = 0, velocityEstimate = 0, velocityIntegrator = 0, lastPositionError = 0;
        unsigned int lastTime;
        int count;
    };

    MouseEncoder leftEncoder = MouseEncoder(LEFT_MOTOR_ENCODER_A, LEFT_MOTOR_ENCODER_B);
    MouseEncoder rightEncoder = MouseEncoder(RIGHT_MOTOR_ENCODER_A, RIGHT_MOTOR_ENCODER_B);

};

#endif // ENCODERS_H
