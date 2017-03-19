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
    explicit GPS(Maze *maze){ this->maze = maze; }

    virtual Cardinal8 nextDirection(const Coordinate start, const Coordinate destination) = 0;

protected:
    Maze *maze;
};

#endif // GPS_H
