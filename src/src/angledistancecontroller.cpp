#include "angledistancecontroller.h"
#include <Arduino.h>
#include <mk20dx128.h>

AngleDistanceController::AngleDistanceController() {

}

double AngleDistanceController::getNewOmega(const double angleTraveled, const double angleSet) {
    const double maxOmega = 3.0;
    if (lastOmega < maxOmega && angleTraveled * 10 < angleSet) {
        lastOmega += 0.001;
    } else {
        lastOmega = maxOmega;
    }
    return maxOmega;
}

int AngleDistanceController::getNewVelocity(const double distTraveled, const double distSet) {
    const int maxVelocity = (5900 * 3) / (4 * 25); // 5900 ticks per sec, times 75%, divided by ticks per mm
    const int minVelocity = (5900) / (4 * 25); // 5900 * 25%
    const int time = millis();

    if (distTraveled < 30 && lastVelocity < maxVelocity) {
        // ramp up
        if (time - lastVelocityTime > 2) {
            lastVelocity++;
            lastVelocityTime = time;
        }
        return lastVelocity;
    } else if (distSet - distTraveled < 30) {
        // ramp down
        if (time - lastVelocityTime > 2 && lastVelocity > minVelocity) {
            lastVelocity--;
            lastVelocityTime = time;
        } else if (time - lastVelocityTime > 2) {
            lastVelocity = minVelocity;
        }
        return lastVelocity;
    } else {
        // constant speed driving
        lastVelocity = maxVelocity;
        return maxVelocity;
    }
}
