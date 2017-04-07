#include "stopgodriver.h"
#include <cmath>

#ifndef BUILD_FOR_PC
StopGoDriver::StopGoDriver() : Driver() {

}
#endif

StopGoDriver::StopGoDriver(AbstractHardwareManager* manager) : Driver(manager) {

}

void StopGoDriver::drive(const Cardinal8 dir) {
    turn(dir);
    manager->drive(180, 0);
    Driver::drive(dir);
}

void StopGoDriver::drive(std::stack<Cardinal8> &path) {
    Cardinal8 next = North;
    int count;
    while (!path.empty()) {
        count = 0;
        next = path.top();
        while (!path.empty() && path.top() == next) {
            path.pop();
            count++;
        }
        turn(next);
        manager->drive(180*count, 0);
    }
}

void StopGoDriver::turn(const Cardinal8 direction) {
    int turns = getTurnsTo(direction);
    double radiansToTurn = (M_PI * turns) / 2;
    manager->drive(0, radiansToTurn);
    updateHeading(direction);
}

void StopGoDriver::drive(const Cardinal8 dir, const int cells) {
    turn(dir);
    updateHeading(dir);
    manager->drive(180*cells, 0);
}
