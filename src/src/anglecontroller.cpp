#include "anglecontroller.h"

AngleController::AngleController() {
    anglePID.SetOutputLimits(-2, 2);
    anglePID.SetSampleTime(1);
    anglePID.SetMode(AUTOMATIC);
}

double AngleController::getNewOmega(const double angleTraveled, const double angleSet) {
    angleInput = angleTraveled;
    angleSetPoint = angleSet;
    anglePID.Compute();
    return omegaOutput;
}
