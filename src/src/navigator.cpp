#include "navigator.h"
using namespace std;
Coordinate Navigator::findUnvisitedCell() {
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++){
            if (!maze.hasMouseVisited(x,y)){
                return Coordinate;
                break;
            }
        }
    }
}



bool Navigator::isDestination(int x, int y) {
    return isCenter(x) && isCenter(y);
}

/*
 * map
 *
 * Check walls and update Maze
 * Get cell location from findUnvisitedCell
 *
 * Use directions from gps to UnvisitedCell from current-
 * location according to Driver and determine the path of travel
 *
 * Send direction to the driver
 */

void Navigator::map(){
//I dont remember what we decidied to name the function for placing walls
//so I just put checkWalls();
vector<Cardinal8> walls = driver.getWalls();
Coordinate destinationCell = findUnvisitedCell();
Coordinate currentCell = driver.getcurrentlocation();
updateMaze(currentCell,walls);
Cardinal8 nextDir = directions.askForDirectionToXY(currentCell, destinationCell);

driver.drive(nextDir);

}

void Navigator::updateMaze(Coordinate cell, std::vector<Cardinal8> walls){
    for(vector<Cardinal8>::iterator it=walls.begin(); it != walls.end(); ++it) {
        maze.placeWall(cell.x,cell.y,*it);
    }

}

