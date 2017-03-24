#include "stopgodriver.h"

#ifndef BUILD_FOR_PC
StopGoDriver::StopGoDriver() : Driver() {

}
#endif

StopGoDriver::StopGoDriver(AbstractHardwareManager* manager) : Driver(manager) {

}

void StopGoDriver::drive(const Cardinal8 dir) {
    Driver::drive(dir);
}

void StopGoDriver::drive(std::stack<Cardinal8> &path) {
    while (!path.empty()) {
        drive(path.top());
        path.pop();
    }
}

void StopGoDriver::turn(const Cardinal8 direction) {
    Driver::turn(direction);
}
