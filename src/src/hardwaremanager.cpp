#include "hardwaremanager.h"
#include "infraredsensorarray.h"

HardwareManager::HardwareManager() {

}

//bool* HardwareManager::areWalls() {
//    bool leftWall = irArray.getLeftIR()>8000;
//    bool centerWall = irArray.getCenterIR()>8000;
//    bool rightWall = irArray.getRightIR()>8000;
//    bool wallData[3] = {leftWall, centerWall, rightWall};
//    return wallData;
//}

bool HardwareManager::isLeftWall() {
    return irArray.getLeftIR() > 8000;
}

bool HardwareManager::isCenterWall() {
    return irArray.getCenterIR() > 8000;
}

bool HardwareManager::isRightWall() {
    return irArray.getRightIR() > 8000;
}
