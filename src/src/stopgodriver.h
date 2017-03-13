#ifndef STOPGODRIVER_H
#define STOPGODRIVER_H
#include "driver.h"

class StopGoDriver : public Driver {
public:
    StopGoDriver();
    virtual void drive(const Cardinal8 dir);
    void turn();
    //turning, updateState, drive forward 1 cell (hardware manager)
private:
    int x, y;

};

#endif // STOPGODRIVER_H
