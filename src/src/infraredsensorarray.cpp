#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensorArray() {

}

InfraredSensorArray::~InfraredSensorArray() {

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

