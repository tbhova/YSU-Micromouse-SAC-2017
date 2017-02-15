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

bool Navigator::isDestination() {
    //Replace Hardcoded cordinates with variable destination
    return isCenter(cell.x) && isCenter(cell.y);
}

//what data type are we saving the path from GPS in? IE what data type will the output of findBox be?
    findBox(x, y) {
        updateMaze();
        Cardinal8 direction = GPS.askForDirectionToXY(CurX, CurY, x, y);
    }

