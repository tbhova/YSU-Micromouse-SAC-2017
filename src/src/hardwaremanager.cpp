#include "hardwaremanager.h"
#include "infraredsensorarray.h"

HardwareManager::HardwareManager() {
//Now lets make it do a thing

}

bool* HardwareManager::areWalls() {
    bool leftWall = InfraredSensorArray.getLeftIR()>8000;
    bool centerWall = InfraredSensorArray.getCenterIR()>8000;
    bool rightWall = InfraredSensorArray.getRightIR()>8000;
    bool wallData[3]={leftWall, centerWall, rightWall};
    return wallData;
}
