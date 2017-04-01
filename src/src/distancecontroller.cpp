#include "distancecontroller.h"

DistanceController::DistanceController(const int maxVelocity) {
    targetStraightSpeed = (3 * maxVelocity) / 4;
    distancePID.SetOutputLimits(-targetStraightSpeed, targetStraightSpeed);
    distancePID.SetSampleTime(5);
    distancePID.SetMode(AUTOMATIC);
}

int DistanceController::getNewVelocity(const int distanceTraveled, const int distance) {
    distanceSetPoint = distance;
    distanceInput = distanceTraveled;
    distancePID.Compute();
    return velocityOutput;
}
