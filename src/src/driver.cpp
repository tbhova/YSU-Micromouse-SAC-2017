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

std::vector<Cardinal8> Driver::getWalls()  {
    std::vector<Cardinal8> walls;
    /*if (manager->isLeftWall()) {
        Serial.print("Left ");
        Serial.println(heading);
        walls.push_back(getLeftDir());
    }
    if (manager->isCenterWall()) {
        Serial.print("Center ");
        Serial.println(heading);
        walls.push_back(getForwardDir());
    }
    if (manager->isRightWall()) {
        Serial.print("Right ");
        Serial.println(heading);
        walls.push_back(getRightDir());
    }*/
    /*if (manager->isCenterWall()){
        walls.push_back(getForwardDir());
    }
    manager->drive(0, M_PI/2);
    if (manager->isCenterWall()){
        walls.push_back(getLeftDir());
    }
    manager->drive(0, -M_PI);

    if (manager->isCenterWall()){
        walls.push_back(getRightDir());
    }*/
    if (manager->isCenterWall()) {
       walls.push_back(getForwardDir());
    }

//    if(((HardwareManager*)manager)->isLeftDetected()) {
//       walls.push_back(getLeftDir());
//    }
//    if(((HardwareManager*)manager)->isRightDetected()) {
//       walls.push_back(getRightDir());
//    }

    manager->drive(0, M_PI/3);

    if (((HardwareManager*)manager)->isLeftWall()) {
       walls.push_back(getLeftDir());
    }
    manager->drive(0, (-2 * M_PI)/3);

    if (((HardwareManager*)manager)->isRightWall()) {
       walls.push_back(getRightDir());
    }
    manager->drive(0, M_PI/3);


    //updateHeading(getRightDir());
    return walls;
}

Cardinal8 Driver::getLeftDir() const {
//    Serial.println(heading);
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
