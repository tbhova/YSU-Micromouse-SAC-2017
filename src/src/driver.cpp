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
