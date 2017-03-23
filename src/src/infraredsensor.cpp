#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensor::InfraredSensor() {

}

unsigned short int InfraredSensor::getDistance() {
    int voltage = analogRead(CENTER_IR_PIN);
    int distance = interpolate.getDistance(voltage);
    return distance;
}
