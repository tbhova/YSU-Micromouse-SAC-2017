#include "navigator.h"
#include <stack>

using namespace std;

Navigator::Navigator(AbstractDriver *driver, Maze *maze, GPS *gps) :
    driver(driver), maze(maze), directions(gps) {

}

Coordinate Navigator::findUnvisitedCell() const {
    for (unsigned int x = 0; x < maze->getSizeX(); x++) {
        for (unsigned int y = 0; y < maze->getSizeY(); y++) {
            if (!maze->hasMouseVisited(x,y)) {
                return Coordinate(x,y);
            }
        }
    }
    //should not reach here if we check whether there are unvisted cells
    return maze->getDestinationCell();
}

void Navigator::map() {
    while (true) {
        Coordinate destinationCell;
        Coordinate currentCell = driver->getCurrentLocation();
        maze->setMouseVisited(currentCell);
        if (maze->isMazeMapped()) {
            break;
        }
        else {
            vector<Cardinal8> walls = driver->getWalls();
            updateMaze(currentCell,walls);
            destinationCell = findUnvisitedCell();
        }

        Cardinal8 nextDir = directions->getDirectionTo(currentCell, destinationCell);
        driver->drive(nextDir);
    }
}

void Navigator::updateMaze(Coordinate cell, std::vector<Cardinal8> walls) {
    for(vector<Cardinal8>::iterator it = walls.begin(); it != walls.end(); ++it) {
        maze->placeWall(cell.x,cell.y,*it);
    }
}

void Navigator::run() {
    if (!maze->isMazeMapped()) {
        map();
    }
    returnToOrigin();

    //TODO add a delay or some type of indication so we can manually reset the bot against the wall
    optimalRoute();
    returnToOrigin();
}

void Navigator::optimalRoute() {
    std::stack<Cardinal8> path = directions->fullPath(Coordinate(0,0), maze->getDestinationCell());
    driver->drive(path);
    returnToOrigin();
}

void Navigator::returnToOrigin() {
    const Coordinate currentCell = driver->getCurrentLocation();
    std::stack<Cardinal8> path = directions->fullPath(currentCell, Coordinate(0,0));
    driver->drive(path);
}
