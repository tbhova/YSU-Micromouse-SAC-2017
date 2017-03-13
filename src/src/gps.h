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
    virtual Cardinal8 nextDirection() = 0;
    /**
     * @brief askForDirectionToXY - Request the directions from current cell to New Cell
     * @param cell - Current Cell
     * @param cell - Destination Cell
     * @return Direction to the new cell
     */
    virtual Cardinal8 askForDirectionToXY(const Coordinate cell, const Coordinate destination) = 0;

protected:
    Maze* maze;
};
#endif // GPS_H
