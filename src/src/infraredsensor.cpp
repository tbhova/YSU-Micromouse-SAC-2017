#include "infraredsensorarray.h"
#include <Arduino.h>
#include <mk20dx128.h>

InfraredSensorArray::InfraredSensor::InfraredSensor(const int pin, InterpolateIR* interpolate) : pin(pin), interpolate(interpolate) {

}

unsigned short int InfraredSensorArray::InfraredSensor::getDistance() const {
    const int voltage = analogRead(pin);
    const int distance = interpolate->getDistance(voltage);
    return distance;
}
