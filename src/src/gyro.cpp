#include "gyro.h"

Gyro::Gyro()
{

}
Sensors sensors;
void Gyro::gyroSetup() {
    Wire.begin();
    sensors.initialize();
}

Vector3 Gyro::getRotation() {
    Vector3 gyro = gyroscope->getRotation();
    return gyro;
 }
