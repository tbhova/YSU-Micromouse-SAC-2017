#include "stopgodriver.h"

StopGoDriver::StopGoDriver() : Driver() {
   x=0;
   y=0;
   dir=North;
}
void StopGoDriver::drive(const Cardinal8 dir) {
    updateState(dir);

}

void StopGoDriver::drive(const GPS &directions) {

}
