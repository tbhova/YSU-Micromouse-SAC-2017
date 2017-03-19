#ifndef BREADTHFIRSTGPS_H
#define BREADTHFIRSTGPS_H

#include "gps.h"
#include "cardinal8.h"
#include <vector>
#include <stack>

class BreadthFirstGPS : public GPS {

protected:
    static std::stack<Cardinal8> getPath(std::vector<std::vector<Cardinal8>> fromWhere,
                                  const Coordinate current, const Coordinate destination);
    std::vector<std::vector<Cardinal8>> search(const Coordinate current, const Coordinate destination);

public:
    explicit BreadthFirstGPS(Maze *maze) : GPS(maze) {}
    virtual ~BreadthFirstGPS() {}
    virtual Cardinal8 getDirectionTo(const Coordinate start, const Coordinate destination);
    virtual std::stack<Cardinal8> fullPath(const Coordinate start, const Coordinate destination);
};

#endif // BREADTHFIRSTGPS_H
