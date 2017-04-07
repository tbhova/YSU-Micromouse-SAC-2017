#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <PID_v1.h>

class MotorController {
public:
    MotorController();
    int getPWM(const int desiredVelocity, const int actualVelocity);
    int getKp(){return velocityPID.GetKp();}
    int getKi(){return velocityPID.GetKi();}
    int getKd(){return velocityPID.GetKd();}
private:

    // Velocity Error Input and setpoint
    double velocityInput = 0, velocitySetPoint = 0;
    // variable output
    double pwmOutput = 0;

    PID velocityPID = PID(&velocityInput, &pwmOutput, &velocitySetPoint, 0.021, 0.074, 0.018, DIRECT);
};

#endif // MOTORCONTROLLER_H
