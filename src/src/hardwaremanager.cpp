#include "hardwaremanager.h"

HardwareManager::HardwareManager() {

}

bool HardwareManager::isLeftWall() const {
    return irArray.getLeftIR() > 8000;
}

bool HardwareManager::isCenterWall() const {
    return irArray.getCenterIR() > 8000;
}

bool HardwareManager::isRightWall() const {
    return irArray.getRightIR() > 8000;
}
