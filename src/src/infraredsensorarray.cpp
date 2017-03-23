#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensorArray() {

}

unsigned short int InfraredSensorArray::getLeftIR() const {
    return leftIR.getDistance();
}

unsigned short int InfraredSensorArray::getCenterIR() const {
    return centerIR.getDistance();
}

unsigned short int InfraredSensorArray::getRightIR() const {
    return rightIR.getDistance();
}
