#include "navigator.h"
using namespace std;

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

void Navigator::map(){
    vector<Cardinal8> walls = driver->getWalls();
    Coordinate destinationCell = findUnvisitedCell();
    Coordinate currentCell = driver->getcurrentlocation();
    updateMaze(currentCell,walls);
    Cardinal8 nextDir = directions->askForDirectionToXY(currentCell, destinationCell);
    driver->drive(nextDir);
}

void Navigator::updateMaze(Coordinate cell, std::vector<Cardinal8> walls){
    for(vector<Cardinal8>::iterator it=walls.begin(); it != walls.end(); ++it) {
        maze->placeWall(cell.x,cell.y,*it);
    }

}

