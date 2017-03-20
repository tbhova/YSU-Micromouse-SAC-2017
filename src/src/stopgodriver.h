#ifndef STOPGODRIVER_H
#define STOPGODRIVER_H
#include "driver.h"

class StopGoDriver : public Driver {
public:
    StopGoDriver();
    virtual void drive(const Cardinal8 dir);
    virtual void drive(const GPS &directions);
    void turn();
    //turning, updateState, drive forward 1 cell (hardware manager)
private:
    int x, y;
    Cardinal8 dir;
};

#endif // STOPGODRIVER_H
