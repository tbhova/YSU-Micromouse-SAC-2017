#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensorArray() {
    interpolate = new InterpolateIR();
}

InfraredSensorArray::~InfraredSensorArray() {
    delete interpolate;
}

unsigned short int InfraredSensorArray::getLeftDistance() const {
    return leftIR.getDistance();
}

unsigned short int InfraredSensorArray::getRightDistance() const {
    return rightIR.getDistance();
}

unsigned short int InfraredSensorArray::getCenterDistance() const {
    return centerIR.getDistance();
}

