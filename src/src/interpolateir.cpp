#include "interpolateir.h"
#include <algorithm>

using namespace std;

short int InterpolateIR::getDistance(const int voltage) const {
    // Too close or far to read voltage
    if (voltage > voltsAt(0)) {
        // if within threshold return lower distance, else -2 for too close
        return voltage - voltsAt(0) < threshold ? distAt(0) : -2;
    } else if (voltage < voltsAt(size - 1)) {
        // if within threshold return upper distance, else -1 for too far
        return voltsAt(size - 1) - voltage < threshold ? distAt(size - 1) : -1;
    }

    // binary search to find location in array - get first element larger than
    const vector<IR_Data>::const_iterator index = upper_bound(sensorCurve.begin(), sensorCurve.end(), IR_Data(voltage, 0));

    if (index == sensorCurve.begin()) {
        return (*index).distance;
    }

    // Linear interpolation to find the actual distance
    double range = (*(index - 1)).voltage - (*index).voltage;
    double interpolationFactor = (double)((*(index - 1)).voltage - voltage) / range;

    double distance = interpolationFactor * (double)((*(index - 1)).distance);
    distance += (1 - interpolationFactor) * (double)((*(index)).distance);

    return distance;
}
