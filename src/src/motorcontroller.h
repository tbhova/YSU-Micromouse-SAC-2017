#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <PID_v1.h>
#include <PID_Autotune_v0.h>

class MotorController {
public:
    MotorController();
    void reset();
    int getPWM(const int desiredVelocity, const int actualVelocity);
    int autoTune(const int actualVelocity);
    int getKp(){return velocityPID.GetKp();}
    int getKi(){return velocityPID.GetKi();}
    int getKd(){return velocityPID.GetKd();}
    bool isAutoDone(){return doneAuto;}
private:

    // Velocity Error Input and setpoint
    double velocityInput = 0, velocitySetPoint = 0;
    // variable output
    double pwmOutput = 0;

    PID velocityPID = PID(&velocityInput, &pwmOutput, &velocitySetPoint, 6.0, 0.38, 0.018,/*6.0, 0.38, 0.018,*/ DIRECT);
    PID_ATune velocityATune = PID_ATune(&velocityInput, &pwmOutput);
    bool doneAuto;
};

#endif // MOTORCONTROLLER_H
