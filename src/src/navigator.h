#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "maze.h"
#include "abstractdriver.h"
#include "gps.h"

/**
 * @brief The Navigator class
 *
 */

class Navigator {
private:
    AbstractDriver *driver;
    Maze *maze;
    GPS *directions;

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
    Coordinate findUnvisitedCell() const;

public:
    Navigator();
    Navigator(AbstractDriver *driver, Maze *maze, GPS *gps);

    /**
     * @brief run - function called by main to either map or travel optimalRoute
     */
    void run();

    /**
     * @brief map - updateMaze with wall data from Driver
     * generate direction and path of travel from current cell to a destination cell
     * pass direction to Driver
     */
    void map();
    void optimalRoute();
    void returnToOrigin();

    void driveStraight();
    void driveStraightIndividualCells();
    void turnRepeatedly();

protected:

};

#endif // NAVIGATOR_H
