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
    while (!path.empty()) {
        drive(path.top());
        path.pop();
    }
}

void StopGoDriver::turn(const Cardinal8 direction) {
    int turns = getTurnsTo(direction);
    double radiansToTurn = (M_PI * turns) / 2;
    manager->drive(0, radiansToTurn);
    updateHeading(direction);
}
