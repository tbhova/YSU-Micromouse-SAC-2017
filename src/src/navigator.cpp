#include "navigator.h"

Coordinate Navigator::findUnvisitedCell() {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++)
                if (!maze.hasMouseVisited(x,y) && !isDestination(x,y)){
                    return Coordinate;
                    break;
                }
        }
}
bool Navigator::isCenter(int i) {
    return (i == 7 || i == 8);
}

bool Navigator::isDestination(int x, int y) {
    return isCenter(x) && isCenter(y);
}

//what data type are we saving the path from GPS in? IE what data type will the output of findBox be?
    findBox(x, y) {
        updateMaze();
        Cardinal8 direction = GPS.askForDirectionToXY(CurX, CurY, x, y);
    }

/*
 * map
 *
 * Check walls and update Maze
 * Get cell location from findUnvisitedCell
 *
 * Use directions from gps to UnvisitedCell from current location according to Driver and determine the path of travel
 * Send direction to the driver
 *
 *
 * /
