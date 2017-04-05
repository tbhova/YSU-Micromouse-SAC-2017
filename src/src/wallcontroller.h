#ifndef WALLCONTROLLER_H
#define WALLCONTROLLER_H

#include <PID_v1.h>
#include <PID_Autotune_v0.h>

class WallController {
public:
    WallController();
    double getNewOmega(const unsigned short int leftWallDistance, const unsigned short int rightWallDistance,
                       const bool isLeftWall, const bool isRightWall);

private:
    // Left and Right wall distance setpoints
    // Equal distance is 110 110
    const double leftWallSetPoint = 100, rightWallSetPoint = 100;

    // Wall Error Input and setpoints
    double wallInput = 0, wallSetPoint = 0;

    // variable outputs
    double wallOmega = 0;

    PID wallPID = PID(&wallInput, &wallOmega, &wallSetPoint, 0.0038, 0.0001, 0.0003, DIRECT);
};

#endif // WALLCONTROLLER_H
