#include "navigator.h"
#include <stack>
#include "breadthfirstgps.h"
#include <Arduino.h>
#include <mk20dx128.h>

using namespace std;

#ifndef BUILD_FOR_PC
#include "stopgodriver.h"
Navigator::Navigator() {
    driver = new StopGoDriver();
    //maze = new Maze(16, 16);
    maze = new Maze(16, 13);
    directions = new BreadthFirstGPS(maze);
}
#endif

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
            Serial.println("mapped");
            break;
        }
        else {
            vector<Cardinal8> walls = driver->getWalls();
            Serial.print(driver->getCurrentLocation().x);
            Serial.print(" , ");
            Serial.print(driver->getCurrentLocation().y);
            Serial.print(" :  ");
            for (int i = 0; i < walls.size(); i++) {
                Serial.print(walls.at(i));
                Serial.print(" ");
            }
            Serial.println(" ");
            updateMaze(currentCell,walls);
            destinationCell = directions->undiscoveredCell(currentCell);//findUnvisitedCell();
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
    driver->drive(North, 0); // reset to face North
}

void Navigator::driveStraight() {
    stack<Cardinal8> path;
    for (int i = 0; i < 8; i++) {
        path.push(South);
    }
    for (int i = 0; i < 12; i++) {
        path.push(North);
    }
    driver->drive(path);
    driver->drive(North, 0);
}

void Navigator::driveStraightIndividualCells() {
    for (int i = 0; i < 12; i++) {
        driver->drive(North);
    }
    for (int i = 0; i < 12; i++) {
        driver->drive(South);
    }
    driver->drive(North, 0);
}

void Navigator::turnRepeatedly() {
//    Serial.println("West");
    driver->drive(West, 0);
    delay(1500);
//    Serial.println("South");
    driver->drive(South, 0);
    delay(1500);
    driver->drive(East, 0);
    delay(1500);
    driver->drive(North, 0);
    delay(1500);
}
