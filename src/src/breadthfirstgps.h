#ifndef BREADTHFIRSTGPS_H
#define BREADTHFIRSTGPS_H

#include "gps.h"
#include "cardinal8.h"
#include <vector>

class BreadthFirstGPS : public GPS
{

protected:
    std::vector<Cardinal8> getPath(const Cardinal8 fromWhere[][16], const Coordinate current, const Coordinate destination);

public:

    virtual Cardinal8 nextDirection(const Coordinate current, const Coordinate destination);
    virtual Cardinal8 nextDirection(){return North;}
    void setMaze(Maze *maze);
};

#endif // BREADTHFIRSTGPS_H
