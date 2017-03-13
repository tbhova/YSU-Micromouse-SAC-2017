#include "infraredsensorarray.h"

InfraredSensorArray::InfraredSensorArray() {

}
short int InfraredSensorArray::getLeftIR() {
    return leftIR.getDistance();
}
short int InfraredSensorArray::getCenterIR() {
    return centerIR.getDistance();
}
short int InfraredSensorArray::getRightIR() {
    return rightIR.getDistance();
}

short int getDistance() {
    //we'll change return value
    return 0;
}
