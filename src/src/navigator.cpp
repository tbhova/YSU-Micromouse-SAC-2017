#include "navigator.h"

Navigator::map() {
        for (int x = 0; x < sizeX; x++) { //This line should be fixed
            for (int y = 0; y < sizeY; y++) //As is this line
                if (!maze.isVisited(x,y) && notDestination (7,7 7,8 8,7 8,8)){ //What is notDestination
                    //I am unsure of what needs to be done to this statement
                    findbox(x,y)
                    break;
                }
        }
    }

    findBox(x, y) { //Does this go here?
        updateMaze();
        Cardinal8 direction = GPS.askForDirectionToXY(curX, CurY, x, y);
    }
}
