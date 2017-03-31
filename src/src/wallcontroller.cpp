#include "wallcontroller.h"

WallController::WallController() {

}

double WallController::getNewOmega(const unsigned short int leftWallDistance, const unsigned short int rightWallDistance,
                                   const bool isLeftWall, const bool isRightWall) {

    // TODO - add wall checkpointing with wall last state
    if (isLeftWall && isRightWall) {
        wallInput = leftWallDistance;
        wallSetPoint = rightWallDistance;
    } else if (isLeftWall) {
        wallInput = leftWallDistance;
        wallSetPoint = leftWallSetPoint;
    } else if (isRightWall) {
        wallInput = rightWallDistance;
        wallSetPoint = rightWallSetPoint;
    } else {
        return 0;
    }

    wallPID.Compute();
    return wallOmega;
}
