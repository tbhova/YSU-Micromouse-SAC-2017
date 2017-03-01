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
//do we want an update heading method or just a heading
//variable that we change in updateState?
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

}
Driver::getForwardDir() {

}
Driver::getRightDir() {

}
//Use math for calculating what direction mouse will face
//method for calculating what direction mouse will face
//Check to see if subtracting int cardnal values wont work right
//
