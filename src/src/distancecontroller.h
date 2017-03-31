#ifndef DISTANCECONTROLLER_H
#define DISTANCECONTROLLER_H

#include <PID_v1.h>
#include <PID_Autotune_v0.h>

class DistanceController {
public:
    explicit DistanceController(const int maxVelocity);
    int getNewVelocity(const int distanceTraveled, const int distance);
private:
    int targetStraightSpeed;

    double distanceInput, distanceSetPoint, velocityOutput;

    PID distancePID = PID(&distanceInput, &velocityOutput, &distanceSetPoint, 0.025, 1.0, 1.25, DIRECT);
};

#endif // DISTANCECONTROLLER_H
