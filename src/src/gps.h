#ifndef GPS_H
#define GPS_H

#include "cardinal8.h"
#include "maze.h"
#include <stack>

/**
 * @brief The gps class
 * Abstract class, all other gps classes should inherit from this
 * Gives directions to the navigator
 */

class GPS {
public:
    explicit GPS(Maze *maze){ this->maze = maze; }
    virtual ~GPS() {}

    /**
     * @brief nextDirection - Request the directions from current cell to New Cell
     * @param start - Current Cell
     * @param destination - Destination Cell
     * @return Direction to the new cell
     */
    virtual Cardinal8 nextDirection(const Coordinate start, const Coordinate destination) = 0;

    virtual std::stack<Cardinal8> fullPath(const Coordinate cell, const Coordinate destination) = 0;

protected:
    Maze* maze;
};

#endif // GPS_H
