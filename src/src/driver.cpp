#include "driver.h"
#include "maze.h"

#include <stdlib.h>

#ifndef BUILD_FOR_PC
#include "hardwaremanager.h"
Driver::Driver() {
    manager = new HardwareManager();
}
#endif

Driver::Driver(AbstractHardwareManager* manager) : manager(manager) {

}

Driver::~Driver() {
    delete manager;
}

void Driver::drive(const Cardinal8 dir, const int cells) {
    for (int i = 0; i < cells; i++) {
        drive(dir);
    }
}
void Driver::drive(const Cardinal8 dir) {
    updateState(dir);
}

void Driver::updateState(const Cardinal8 direction) {
    Coordinate cell = Maze::adjacentCell(x, y, direction);
    x = cell.x;
    y = cell.y;
    updateHeading(direction);
}

void Driver::updateHeading(const Cardinal8 direction) {
    heading = direction;
}


int Driver::getTurnsTo(const Cardinal8 direction) const {
     int distance = (static_cast<int>(direction) - static_cast<int>(heading)) / 2;
     if (distance < -2) {
         distance += 4;
     } else if (distance > 2) {
         distance -= 4;
     }
     return distance;
}

std::vector<Cardinal8> Driver::getWalls() const {
    std::vector<Cardinal8> walls;
    if (manager->isLeftWall()) {
        walls.push_back(getLeftDir());
    }
    if (manager->isCenterWall()) {
        walls.push_back(getForwardDir());
    }
    if (manager->isRightWall()) {
        walls.push_back(getRightDir());
    }

    return walls;
}

Cardinal8 Driver::getLeftDir() const {
    int leftDir = (static_cast<int>(heading) + 2) % 8;
    return static_cast<Cardinal8>(leftDir);
}

Cardinal8 Driver::getForwardDir() const {
    return heading;
}

Cardinal8 Driver::getRightDir() const {
    int rightDir = static_cast<int>(heading) - 2;
    if (rightDir < 0) {
        rightDir += 8;
    }
    return static_cast<Cardinal8>(rightDir);
}

Coordinate Driver::getCurrentLocation() const {
    return Coordinate(x, y);
}

unsigned int Driver::getX() const {
    return x;
}

unsigned int Driver::getY() const {
    return y;
}

Cardinal8 Driver::getHeading() const {
    return heading;
}
