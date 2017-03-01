#include "hardwaremanager.h"

HardwareManager::HardwareManager() {
//Now lets make it do a thing

}

bool* areWalls() {
bool leftWall = getLeftIR()>8000;
bool centerWall = getCenterIR()>8000;
bool rightWall = getRightIR()>8000;
bool wallData[3]={leftWall, centerWall, rightWall};
return wallData;
}
