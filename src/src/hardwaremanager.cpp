#include "hardwaremanager.h"

HardwareManager::HardwareManager() {
//Now lets make it do a thing
getIRData();


}
short int* getIRData() {
    short int irData[3]={getLeftIR(), getCenterIR(), getRightIR()};
    return irData;
}
