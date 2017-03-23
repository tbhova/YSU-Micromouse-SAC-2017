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
    virtual void drive(const Cardinal8 dir);
    virtual Coordinate getCurrentLocation() const;
    virtual std::vector<Cardinal8> getWalls() const;
    unsigned int getX() const;
    unsigned int getY() const;
    Cardinal8 getHeading() const;

protected:
    void updateState(const Cardinal8 direction);
    void updateHeading(const Cardinal8 direc);
    int getTurnsTo(const Cardinal8 direction) const;
    virtual void turn(const Cardinal8 direction);
    Cardinal8 getLeftDir() const;
    Cardinal8 getRightDir() const;
    Cardinal8 getForwardDir() const;
    HardwareManager* getHwManager() const { return manager; }

private:
    unsigned int x = 0, y = 0;
    Cardinal8 dir = North;
    HardwareManager *manager;

};

#endif // DRIVER_H
