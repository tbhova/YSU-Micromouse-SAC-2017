#ifndef BREADTHFIRSTGPS_H
#define BREADTHFIRSTGPS_H

#include "gps.h"
#include "cardinal8.h"

class BreadthFirstGPS : public GPS
{
public:
    BreadthFirstGPS();
    virtual ~BreadthFirstGPS();
    virtual Cardinal8 nextDirection();
};

#endif // BREADTHFIRSTGPS_H
