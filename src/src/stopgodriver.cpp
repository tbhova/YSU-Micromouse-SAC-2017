#include "stopgodriver.h"

StopGoDriver::StopGoDriver() : Driver() {

}

StopGoDriver::StopGoDriver(HardwareManager* manager) : Driver(manager) {

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
