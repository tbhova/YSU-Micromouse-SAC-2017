#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensorArray() {

}

unsigned short int InfraredSensorArray::getLeftDistance() {
    return leftIR.getDistance();
}

unsigned short int InfraredSensorArray::getRightDistance() {
    return rightIR.getDistance();
}

unsigned short int InfraredSensorArray::getCenterDistance() {
    return centerIR.getDistance();
}
