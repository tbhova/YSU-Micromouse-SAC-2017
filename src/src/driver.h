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
    virtual Coordinate getCurrentLocation();
    virtual std::vector<Cardinal8> getWalls();
    unsigned int getX() const;
    unsigned int getY() const;
    Cardinal8 getDir();

protected:
    void updateState(Cardinal8 direction);
    void updateHeading(Cardinal8 direc);
    int numTurns(Cardinal8 direction);
    Cardinal8 getLeftDir();
    Cardinal8 getRightDir();
    Cardinal8 getForwardDir();
    virtual void turn(Cardinal8 direc);
    HardwareManager* getHwManager() { return manager; }

private:
    unsigned int x = 0, y = 0;
    Cardinal8 dir = North;
    HardwareManager *manager;

};

#endif // DRIVER_H
