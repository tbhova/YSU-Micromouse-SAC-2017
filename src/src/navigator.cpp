#include "navigator.h"

Navigator::findUnvisitedCell() {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++)
                if (!Maze.hasMouseVisited(x,y) && isDestination(x,y)){
                    findbox(x,y);
                    break;
                }
        }
}
Navigator::isDestination() {
    //Replace Hardcoded cordinates with variable destination
    if ( cell == (7,7) || (7,8) || (8,7) || (8,8) ) {
        return false;
    else
        return true;
    }
}
//what data type are we saving the path from GPS in? IE what data type will the output of findBox be?
    findBox(x, y) {
        updateMaze();
        Cardinal8 direction = GPS.askForDirectionToXY(CurX, CurY, x, y);
    }

