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
    GPS(){}
    GPS(Maze *maze){ this->maze = maze; }

    virtual Cardinal8 nextDirection() = 0;

protected:
    Maze *maze;
};

#endif // GPS_H
