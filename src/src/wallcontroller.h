#ifndef WALLCONTROLLER_H
#define WALLCONTROLLER_H

#include <PID_v1.h>
#include <PID_Autotune_v0.h>

class WallController {
public:
    WallController();
    double getNewOmega(const unsigned short int leftWallDistance, const unsigned short int rightWallDistance,
                       const bool isLeftWall, const bool isRightWall);
    void reset();

private:
    // Left and Right wall distance setpoints
    // Equal distance is 110 110
    const double leftWallSetPoint = 110, rightWallSetPoint = 110;

    // Wall Error Input and setpoints
    double wallInput = 0, wallSetPoint = 0;

    // variable outputs
    double wallOmega = 0;

    PID wallPID = PID(&wallInput, &wallOmega, &wallSetPoint, 0.0188, 0.0001, 0.00025, DIRECT);

    void initPID();
};

#endif // WALLCONTROLLER_H
