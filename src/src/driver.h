#ifndef DRIVER_H
#define DRIVER_H

#include "gps.h"
#include "cardinal8.h"
#include "hardwaremanager.h"
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
    void updateState(Cardinal8 direction);
    void updateHeading(Cardinal8 direc);
    int numTurns(Cardinal8 direction);
    Cardinal8 getLeftDir();
    Cardinal8 getRightDir();
    Cardinal8 getForwardDir();

private:
    int x, y;
    Cardinal8 dir;
    HardwareManager manager;

};

#endif // DRIVER_H
