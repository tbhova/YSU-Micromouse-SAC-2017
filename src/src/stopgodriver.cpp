#include "stopgodriver.h"

StopGoDriver::StopGoDriver() : Driver() {
   x=0;
   y=0;
   dir=North;
}

void StopGoDriver::drive(const Cardinal8 dir) {
    updateState(dir);

}

void StopGoDriver::drive(std::stack<Cardinal8> &path) {
    while (!path.empty()) {
        drive(path.top());
        path.pop();
    }
}
