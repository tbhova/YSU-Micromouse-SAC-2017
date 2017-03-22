#ifndef BUILD_FOR_PC

#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensorArray() {

}
unsigned short int InfraredSensorArray::getLeftIR() {
    return leftIR.getDistance();
}
unsigned short int InfraredSensorArray::getCenterIR() {
    return centerIR.getDistance();
}
unsigned short int InfraredSensorArray::getRightIR() {
    return rightIR.getDistance();
}

short int getDistance() {
    //we'll change return value
    return 0;
}

#endif // BUILD_FOR_PC
