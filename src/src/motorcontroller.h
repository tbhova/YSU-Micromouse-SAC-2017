#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <PID_v1.h>
#include <PID_Autotune_v0.h>

class MotorController {
public:
    MotorController();
    int getPWM(const int desiredVelocity, const int actualVelocity);

private:

    // Velocity Error Input and setpoint
    double velocityInput = 0, velocitySetPoint = 0;

    // variable output
    double pwmOutput = 0;

    PID velocityPID = PID(&velocityInput, &pwmOutput, &velocitySetPoint, 2.1, 0.74, 1.8, DIRECT);
};

#endif // MOTORCONTROLLER_H
