#ifndef ABSTRACTDRIVER_H
#define ABSTRACTDRIVER_H

#include "gps.h"

class AbstractDriver {
public:
    virtual ~AbstractDriver() {}
    virtual void drive(const GPS &directions) = 0;
    virtual void drive(const Cardinal8 dir, const int cells) = 0;
    virtual void drive(const Cardinal8 dir) = 0;
    virtual Coordinate getCurrentLocation() = 0;
    virtual std::vector<Cardinal8> getWalls() = 0;
};

#endif // ABSTRACTDRIVER_H
