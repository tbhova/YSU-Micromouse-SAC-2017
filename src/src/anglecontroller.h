#ifndef ANGLECONTROLLER_H
#define ANGLECONTROLLER_H

#include <PID_v1.h>
#include <PID_Autotune_v0.h>

class AngleController {
public:
    AngleController();
    double getNewOmega(const double angleTraveled, const double angleSet);
private:
    double angleInput, angleSetPoint, omegaOutput;

    PID anglePID = PID(&angleInput, &omegaOutput, &angleSetPoint, 0.025, 1.0, 1.25, DIRECT);
};

#endif // ANGLECONTROLLER_H
