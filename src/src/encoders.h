#ifndef ENCODERS_H
#define ENCODERS_H

class Encoders {

public:
    Encoders();
    void reset(int reset);
    int getLeftSpeed();
    int getRightSpeed();
    int getLeftTicks();
    int getLeftTicks();

private:
    class MouseEncoder {
    public:
        MouseEncoder(const int encoderA, const int encoderB);
        ~MouseEncoder();
        int getSpeed();
        int getTicks();

    private:
        Encoder* encoder;
        const int kp = 4, ki = 90;
        int positionEstimate = 0, velocityEstimate = 0, velocityIntegrator = 0;
        unsigned int lastTime;
    };

    MouseEncoder leftEncoder(LEFT_MOTOR_ENCODER_A, LEFT_MOTOR_ENCODER_B);
    MouseEncoder rightEncoder(RIGHT_MOTOR_ENCODER_A, RIGHT_MOTOR_ENCODER_B);

};

#endif // ENCODERS_H
