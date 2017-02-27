#ifndef MOUSEDRIVER_H
#define MOUSEDRIVER_H
#include "driver.h"

class MouseDriver : public Driver {
public:
    MouseDriver();
    virtual void drive(const Cardinal8 dir);
    //turning, updateState, drive forward 1 cell(hardware manager
};

#endif // MOUSEDRIVER_H
