#include "gyro.h"

Gyro::Gyro()
{
Sensors sensors;
}
void Gyro::gyroSetup() {
    Wire.begin();
    Sensors.intialize();
}

virtual Vector3 Gyro::getRotation() {
    Vector3 gyro = gyroscope->getRotation();
 }
