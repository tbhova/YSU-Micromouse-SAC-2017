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

    Coordinate askForDirectionToXY(Coordinate cell, Coordinate cell, Coordinate cell, Coordinate cell);

protected:
    Maze &maze;
};

    askForDirectionToXY(Coordinate cell,Coordinate cell, Coordinate cell, Coordinate cell) {




#endif // GPS_H
