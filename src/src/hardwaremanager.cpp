#include "hardwaremanager.h"

HardwareManager::HardwareManager() {

}

bool HardwareManager::isLeftWall() const {
    return irArray.getLeftDistance() > 8000;
}

bool HardwareManager::isCenterWall() const {
    return irArray.getCenterDistance() > 8000;
}

bool HardwareManager::isRightWall() const {
    return irArray.getRightDistance() > 8000;
}
