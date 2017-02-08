#include "navigator.h"

Coordinate Navigator::findUnvisitedCell() {
        for (int x = 0; x < sizeX; x++) { //This line should be fixed
            for (int y = 0; y < sizeY; y++) //As is this line
                if (maze.hasMouseVisited((x,y) && notDestination (7,7 7,8 8,7 8,8)){
                    //I am unsure of what else needs to be done to this statement
                    find box(x,y)
                    break;
                }
        }
    }
}
    findBox(x, y) { //Does this go here?
        updateMaze();
        Cardinal8 direction = GPS.askForDirectionToXY(CurX, CurY, x, y);
    }
}
