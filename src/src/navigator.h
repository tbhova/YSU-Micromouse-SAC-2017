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
public:
    Navigator();
    void run();

protected:
    void map();
    void optimalRoute();

private:
    Driver driver;
    GPS directions;
    Maze maze;
};

#endif // NAVIGATOR_H
