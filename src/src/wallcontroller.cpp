#include "wallcontroller.h"

WallController::WallController() {
    initPID();
}

double WallController::getNewOmega(const unsigned short int leftWallDistance, const unsigned short int rightWallDistance,
                                   const bool isLeftWall, const bool isRightWall) {

    // TODO - add wall checkpointing with wall last state
    if (isLeftWall && isRightWall) {
        wallInput = rightWallDistance;
        wallSetPoint = leftWallDistance;
    } else if (isLeftWall) {
        wallInput = 2 * leftWallSetPoint;
        wallSetPoint = 2 * leftWallDistance;
    } else if (isRightWall) {
        wallInput = 2 * rightWallDistance;
        wallSetPoint = 2 * rightWallSetPoint;
    } else {
        return 0;
    }

    wallPID.Compute();
    return wallOmega;
}

void WallController::reset() {
    wallInput = 0, wallSetPoint = 0;
    initPID();
}

void WallController::initPID() {
    wallPID = PID(&wallInput, &wallOmega, &wallSetPoint, 0.0038, 0.0001, 0.0003, DIRECT);
    wallPID.SetOutputLimits(-2, 2);
    wallPID.SetSampleTime(7);
    wallPID.SetMode(AUTOMATIC);
}
