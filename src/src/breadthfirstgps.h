#ifndef BREADTHFIRSTGPS_H
#define BREADTHFIRSTGPS_H

#include "gps.h"
#include "cardinal8.h"
#include <vector>
#include <stack>
class BreadthFirstGPS : public GPS
{

protected:
    std::stack<Cardinal8> getPath(std::vector<std::vector<Cardinal8>>
                                   fromWhere, const Coordinate current, const Coordinate destination);
    std::vector<std::vector<Cardinal8>> search(const Coordinate current, const Coordinate destination);
public:
    BreadthFirstGPS(Maze *maze){this->maze = maze;}

    virtual Cardinal8 nextDirection(const Coordinate start, const Coordinate destination);
    virtual Cardinal8 nextDirection(){return North;}

};

#endif // BREADTHFIRSTGPS_H
