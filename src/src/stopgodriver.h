#ifndef STOPGODRIVER_H
#define STOPGODRIVER_H

#include "gps.h"
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

    virtual void drive(const Cardinal8 dir);
    virtual void drive(const Cardinal8 dir, const int cells);
    virtual void drive(std::stack<Cardinal8> &path);
};

#endif // STOPGODRIVER_H
