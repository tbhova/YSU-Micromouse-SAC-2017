#ifndef DRIVER_H
#define DRIVER_H

#include "gps.h"
#include "cardinal8.h"
#include "abstractdriver.h"

/**
 * @brief The driver class
 * Abstract class, all other drivers should inherit from this
 */

class Driver : public AbstractDriver {
public:
    Driver();
    virtual Coordinate getCurrentLocation();
    virtual std::vector<Cardinal8> getWalls();
};

#endif // DRIVER_H
