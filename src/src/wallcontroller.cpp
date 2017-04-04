#include "wallcontroller.h"

WallController::WallController() {
    wallPID.SetOutputLimits(-2, 2);
    wallPID.SetSampleTime(1);
    wallPID.SetMode(AUTOMATIC);
}

double WallController::getNewOmega(const unsigned short int leftWallDistance, const unsigned short int rightWallDistance,
                                   const bool isLeftWall, const bool isRightWall) {

    // TODO - add wall checkpointing with wall last state
    if (isLeftWall && isRightWall) {
        wallInput = rightWallDistance;
        wallSetPoint = leftWallDistance;
    } else if (isLeftWall) {
        wallInput = leftWallSetPoint;
        wallSetPoint = leftWallDistance;
    } else if (isRightWall) {
        wallInput = rightWallDistance;
        wallSetPoint = rightWallSetPoint;
    } else {
        return 0;
    }

    wallPID.Compute();
    return wallOmega;
}
