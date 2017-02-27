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
    Driver *driver;
    GPS *directions;
    Maze maze;

    /**
     * @brief updateMaze - Collects wall data from the Driver and updates the maze model with walls
     * @param cell
     * @param walls
     */
    void updateMaze(Coordinate cell, std::vector<Cardinal8> walls);

    /**
     * @brief findUnvisitedCell - determine the Coordinates of the nearest UnvisitedCell
     * @return Coordinates of the the nearest UnvisitedCell
     */
    Coordinate findUnvisitedCell();

public:
    Navigator();

    /**
     * @brief run - function called by main to either map or travel optimalRoute
     */
    void run();


protected:
    /**
     * @brief map - updateMaze with wall data from Driver
     * generate direction and path of travel from current cell to a destination cell
     * pass direction to Driver
     */
    void map();
    void optimalRoute();


};

#endif // NAVIGATOR_H
