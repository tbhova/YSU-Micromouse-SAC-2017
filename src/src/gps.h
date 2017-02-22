#ifndef GPS_H
#define GPS_H

#include "cardinal8.h"
#include "maze.h"

/**
 * @brief The gps class
 * Abstract class, all other gps classes should inherit from this
 * Gives directions to the navigator
 */

class GPS {
public:
    GPS();
    virtual Cardinal8 nextDirection() = 0;
    /**
     * @brief askForDirectionToXY - Request the directions from current cell to New Cell
     * @param cell - Current Cell
     * @param cell - Destination Cell
     * @return Direction to the new cell
     */
    Cardinal8 askForDirectionToXY(Coordinate cell, Coordinate cell);

protected:
    Maze &maze;
};
#endif // GPS_H
