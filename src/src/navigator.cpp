#include "navigator.h"
#include <stack>

using namespace std;

Navigator::Navigator(AbstractDriver *driver, Maze *maze, GPS *gps) :
    driver(driver), maze(maze), directions(gps) {

}

Coordinate Navigator::findUnvisitedCell() {
    for (int x = 0; x < maze->getSizeX(); x++) {
        for (int y = 0; y < maze->getSizeY(); y++) {
            if (!maze->hasMouseVisited(x,y)) {
                return Coordinate(x,y);
            }
        }
    }
    //should not reach here if we check whether there are unvisted cells
    return maze->getDestinationCell();
}

void Navigator::map() {
    Coordinate destinationCell;
    while (true) {
        Coordinate currentCell = driver->getCurrentLocation();
        if (maze->isMazeMapped()) {
            destinationCell = Coordinate(0, 0);
            if (currentCell == destinationCell) {
                break;
            }
        }
        else {
            vector<Cardinal8> walls = driver->getWalls();
            updateMaze(currentCell,walls);
            destinationCell = findUnvisitedCell();
        }

        Cardinal8 nextDir = directions->askForDirectionToXY(currentCell, destinationCell);
        driver->drive(nextDir);
    }
}

void Navigator::updateMaze(Coordinate cell, std::vector<Cardinal8> walls) {
    for(vector<Cardinal8>::iterator it=walls.begin(); it != walls.end(); ++it) {
        maze->placeWall(cell.x,cell.y,*it);
    }
}

void Navigator::run() {
    if (!maze->isMazeMapped()) {
        map();
    }
    //TODO add a delay or some type of indication so we can manually reset the bot against the wall
    optimalRoute();
}

void Navigator::optimalRoute() {
    std::stack<Cardinal8> path = directions->fullPath(Coordinate(0,0), maze->getDestinationCell());
    std::stack<Cardinal8> reversePath = std::stack<Cardinal8>();

    while (true) {
        Cardinal8 nextDir;
        if (!path.empty()) {
            nextDir = path.top();
            path.pop();
            reversePath.push(nextDir);
        } else {
            nextDir = reversePath.top();
            reversePath.pop();
        }
        driver->drive(nextDir);
    }
}
