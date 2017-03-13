#ifndef STOPGODRIVER_H
#define STOPGODRIVER_H
#include "driver.h"

class StopGoDriver : public Driver {
public:
    topGoDriver();
    virtual void drive(const Cardinal8 dir);
    void turn()
    //turning, updateState, drive forward 1 cell (hardware manager)

};

#endif // STOPGODRIVER_H
