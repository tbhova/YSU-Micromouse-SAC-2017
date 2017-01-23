#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "maze.h"
#include "driver.h"
#include "gps.h"

/**
 * @brief The Navigator class
 *
 */

class Navigator {
private:
    //Memeber Data
    Driver driver;
    GPS directions;
    Maze maze;

    void updateMaze(); //Get wall data from Driver and adjust maze

    Coordinate findUnvisitedCell();
        //Search maze for a cell.visited = false
        //determine coordinates of cell

public:
    Navigator();

    //this will be called by main - findUnvisitedCell with maze,
    //use GPS to find direction to that cell, inform driver of direction
    //Loop this until all cells are visited

    void run();


protected:

    void map();
    void optimalRoute();


};

#endif // NAVIGATOR_H
