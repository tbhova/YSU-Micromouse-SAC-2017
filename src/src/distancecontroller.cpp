#include "distancecontroller.h"

DistanceController::DistanceController(const int maxVelocity) {
    targetStraightSpeed = (3 * maxVelocity) / 4;
    distancePID.SetOutputLimits(-targetStraightSpeed, targetStraightSpeed);
    distancePID.SetSampleTime(5);
    distancePID.SetMode(AUTOMATIC);
}

void DistanceController::updateSetPoint(const int distance) {
    distanceSetPoint = distance;
}

int DistanceController::getNewVelocity(const int distanceTraveled) {
    distanceInput = distanceTraveled;
    distancePID.Compute();
    return velocityOutput;
}
