#include "hardwaremanager.h"
#include "infraredsensorarray.h"

bool * HardwareManager::areWalls() {
    bool leftWall = irArray.getLeftIR()>8000;
    bool centerWall = irArray.getCenterIR()>8000;
    bool rightWall = irArray.getRightIR()>8000;
    static bool wallData[3] = {leftWall, centerWall, rightWall};
    return wallData;
}
