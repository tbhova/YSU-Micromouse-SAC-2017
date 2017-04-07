#ifndef STOPGODRIVER_H
#define STOPGODRIVER_H

#include "cardinal8.h"
#include "driver.h"
#include <stack>

/**
 * @brief The StopGoDriver class
 * Driver that stops after each move
 * Turns are made in place
 */

class StopGoDriver : public Driver {
public:
    StopGoDriver();
    explicit StopGoDriver(AbstractHardwareManager* manager);
    virtual void drive(const Cardinal8 dir);
    virtual void drive(std::stack<Cardinal8> &path);
    virtual void drive(const Cardinal8 dir, const int cells);

protected:
    virtual void turn(const Cardinal8 direction);
    //turning, updateState, drive forward 1 cell (hardware manager)

};

#endif // STOPGODRIVER_H
