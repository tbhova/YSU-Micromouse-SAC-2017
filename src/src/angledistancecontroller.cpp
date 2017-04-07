#include "angledistancecontroller.h"
#include <Arduino.h>
#include <mk20dx128.h>
#include <cmath>

AngleDistanceController::AngleDistanceController() {

}

double AngleDistanceController::getNewOmega(const double angleTraveled, const double angleSet) {
    const int reverse = angleSet < 0 ? -1 : 1;
    const double angleTraveledAbs = fabs(angleTraveled);
    const double angleSetAbs = fabs(angleSet);
    const double maxOmega = 3.0;
    if (lastOmega < maxOmega && angleTraveledAbs * 10 < angleSetAbs) {
        lastOmega += 0.001;
    } else {
        lastOmega = maxOmega;
    }
    return maxOmega * reverse;
}

int AngleDistanceController::getNewVelocity(const double distTraveled, const double distSet) {
    const int maxVelocity = (5900 * 3) / (4 * 25); // 5900 ticks per sec, times 75%, divided by ticks per mm
    const int minVelocity = (5900) / (10 * 25); // 5900 * 10%
    const int time = millis();
//    Serial.print("last velocity ");
//    Serial.println(lastVelocity);
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
        return lastVelocity;
    }
}
