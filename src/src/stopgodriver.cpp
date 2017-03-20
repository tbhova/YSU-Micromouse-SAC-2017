#include "stopgodriver.h"

StopGoDriver::StopGoDriver() {

}

void StopGoDriver::drive(const Cardinal8 dir) {

}

void StopGoDriver::drive(std::stack<Cardinal8> &path) {
    while (!path.empty()) {
        drive(path.top());
        path.pop();
    }
}
