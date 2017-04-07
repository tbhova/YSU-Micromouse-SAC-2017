#ifndef WALLCONTROLLER_H
#define WALLCONTROLLER_H

#include <PID_v1.h>

class WallController {
public:
    WallController();
    double getNewOmega(const unsigned short int leftWallDistance, const unsigned short int rightWallDistance,
                       const bool isLeftWall, const bool isRightWall);

private:
    // Left and Right wall distance setpoints
    const double leftWallSetPoint = 65, rightWallSetPoint = 65;

    // Wall Error Input and setpoints
    double wallInput = 0, wallSetPoint = 0;

    // variable outputs
    double wallOmega = 0;

    PID wallPID = PID(&wallInput, &wallOmega, &wallSetPoint, 2.1, 0.74, 4.8, DIRECT);
};

#endif // WALLCONTROLLER_H
