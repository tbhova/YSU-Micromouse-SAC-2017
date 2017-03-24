#include "infraredsensorarray.h"
#include <Arduino.h>
#include "mk20dx128.h"
#include "pins.h"

InfraredSensorArray::InfraredSensor::InfraredSensor(int pin, InterpolateIR* interpolate) {

}

unsigned short int InfraredSensorArray::InfraredSensor::getDistance() const {
    int voltage = analogRead(IR_SENSOR_LEFT);
    int distance = interpolate.getDistance(voltage);
    return distance;
}
