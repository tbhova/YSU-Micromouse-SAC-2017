#ifndef DRIVER_H
#define DRIVER_H

#include "gps.h"
#include "cardinal8.h"

/**
 * @brief The driver class
 * Abstract class, all other drivers should inherit from this
 */

class Driver {
public:
    Driver();

    virtual void drive(const GPS &directions) = 0;
    virtual void drive(const Cardinal8 dir, const int cells) = 0;
    virtual void drive(const Cardinal8 dir) = 0;
    Coordinate getcurrentlocation();
    std::vector<Cardinal8> getWalls();
};

#endif // DRIVER_H
