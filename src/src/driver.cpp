#include "driver.h"
#include "maze.h"
#include <stdlib.h>

void Driver::drive(const Cardinal8 dir, const int cells) {
    for (int i=0; i<cells; i++) {
        drive(dir);
    }
}
void Driver::drive(const Cardinal8 dir) {
    updateState(dir);
}

void Driver::updateState(Cardinal8 direction) {
    Coordinate cell = Maze::adjacentCell(x,y,direction);
    x=cell.x;
    y=cell.y;
    dir=direction;

}

void Driver::updateHeading(Cardinal8 direc) {
    dir=direc;
}


int Driver::numTurns(Cardinal8 direction) {
     return ((int)direction-(int)dir);
}
std::vector<Cardinal8> Driver::getWalls() {
    bool* areWalls=manager.areWalls();
    std::vector<Cardinal8> walls;
            if(areWalls[0]) {
                walls.push_back(getLeftDir());
            }
            if(areWalls[1]) {
                walls.push_back(getForwardDir());
            }
            if(areWalls[2]) {
                walls.push_back(getRightDir());
            }

    return walls;
}
Cardinal8 Driver::getLeftDir() {
   int leftDir=(int)dir+2;
    if(leftDir>8) {
        leftDir-=8;
    }
    return (Cardinal8)leftDir;
}

Cardinal8 Driver::getForwardDir() {
    return dir;
}

Cardinal8 Driver::getRightDir() {
    int rightDir=(int)dir-2;
    if(rightDir<0) {
        rightDir+=8;
    }
    return (Cardinal8)rightDir;
}
Coordinate Driver::getCurrentLocation() {
    return Coordinate(x,y);
}
void Driver::turn(Cardinal8 direc) {
    int turns = (dir-direc)/2;
    updateHeading(dir);
    for(int i=0; i<abs(turns); i++) {
        if(turns<0) {
         // turnleft();
        }
        else
          break;
          // turnright();
    }
}
