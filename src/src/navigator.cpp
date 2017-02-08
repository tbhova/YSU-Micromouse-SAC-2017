#include "navigator.h"

Navigator::findUnvisitedCell() {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++)
                if (maze.hasMouseVisited((x,y) && /*notDestination (7,7 7,8 8,7 8,8)*/)){
                    //I am unsure of what else needs to be done to this statement
                    //findbox(x,y);
                    break;
                }
        }
}
Navigator::isDestination() {
    //Replace Hardcoded cordinates with variable
    if ( cell == (7,7) || (7,8) || (8,7) || (8,8) ) {
        return true;
    else
        return false;
    }
}
    findBox(x, y) { //Does this go here?
        updateMaze();
        Cardinal8 direction = GPS.askForDirectionToXY(CurX, CurY, x, y);
    }
}
