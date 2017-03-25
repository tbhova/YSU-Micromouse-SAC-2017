#ifndef ENCODERS_H
#define ENCODERS_H

class Encoders {

public:
    Encoders();
    int getLeftSpeed();
    int getRightSpeed();

private:
    class Encoder {
    public:
        Encoder();
        int getSpeed();
        int getTicks();

    private:
        const int kp = 4, ki = 90;
        int positionEstimate = 0, velocityEstimate = 0, velocityIntegrator = 0;
        unsigned int lastTime;
    };

    Encoder rightEncoder, leftEncoder;
};

#endif // ENCODERS_H
