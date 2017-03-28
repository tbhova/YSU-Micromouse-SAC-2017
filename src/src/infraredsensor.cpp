#include "infraredsensorarray.h"
#include <Arduino.h>
#include "mk20dx128.h"
#include "pins.h"

InfraredSensorArray::InfraredSensor::InfraredSensor(int pin, InterpolateIR* interpolate) {
    this->pin=pin;
    this->interpolate=interpolate;
}

unsigned short int InfraredSensorArray::InfraredSensor::getDistance() const {
    Serial.printf("%p", interpolate);
    int voltage = analogRead(pin);
    int distance = interpolate->getDistance(voltage);
    return distance;
}
