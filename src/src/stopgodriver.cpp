#include "stopgodriver.h"

StopGoDriver::StopGoDriver() {
   x=0;
   y=0;
   dir=North;
}
virtual void StopGoDriver::drive(const Cardinal8 dir) {
    updateState(dir);


}

