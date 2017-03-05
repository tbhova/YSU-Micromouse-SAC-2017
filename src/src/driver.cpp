#include "driver.h"
#include "maze.h"

void Driver::drive(const Cardinal8 dir, const int cells) {
    for (int i=0; i<cells; i++) {
        drive(dir);

    }
}

void Driver::updateState(Cardinal8 direction) {
    Coordinate cell = Maze.adjacentCell(x,y,direction);
    x=cell.x;
    y=cell.y;
    dir=direction;

}

void Driver::updateHeading() {

}
Driver::numTurns(Cardinal8 direction) {
     return ((int)direction-(int)dir);
}
std::vector<Cardinal8> getWalls() {
    bool areWalls[3]=manager.areWalls();
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



}
Driver::getLeftDir() {
    leftDir=(int)dir+2;
    if(leftDir>8) {
        leftDir-8;
    }
    return (Cardinal8)leftDir;
}

Driver::getForwardDir() {
    return dir;
}

Driver::getRightDir() {
    rightDir=(int)dir-2;
    if(rightDir<0) {
        rightDir+8;
    }
    return (Cardinal8)rightDir;
}

