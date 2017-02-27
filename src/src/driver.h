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
    virtual void drive(const Cardinal8 dir, const int cells);
    virtual Coordinate getcurrentlocation();
    virtual std::vector<Cardinal8> getWalls();
    int getX() const;
    int getY() const;

protected:
    Cardinal8 getDir();
    void updateState(Cardinal8);
    void updateHeading();

private:
    int x, y;
    Cardinal8 dir;
};

#endif // DRIVER_H
