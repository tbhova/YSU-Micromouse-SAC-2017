#include "interpolateir.h"
#include <algorithm>

using namespace std;

unsigned short int InterpolateIR::getDistance(const int voltage) const {
    // Too close or far to read voltage
    if (voltage >= voltsAt(0)) {
        return distAt(0);
    } else if (voltage <= voltsAt(size - 1)) {
        return distAt(size - 1);
    }

    // binary search to find location in array - get first element larger than
    const vector<IR_Data>::const_iterator index = upper_bound(sensorCurve.begin(), sensorCurve.end(), IR_Data(voltage, 0));

    if (index == sensorCurve.begin()) {
        return (*index).distance;
    }

    // Linear interpolation to find the actual distance
    double range = (*(index - 1)).voltage - (*index).voltage;
    double interpolationFactor = (double)((*(index - 1)).voltage - voltage) / range;

    double distance = interpolationFactor * (double)((*(index)).distance);
    distance += (1 - interpolationFactor) * (double)((*(index - 1)).distance);

    return distance;
}
