#ifndef GYRO_H
#define GYRO_H
#define SENSORS_MPU6050_ATTACHED
#include <Sensors.h>
#include <Wire.h>
#include "pins.h"
class Gyro
{
public:
   Gyro();
   void gyroSetup();
   virtual Vector3 getRotation();

private:
   Gyroscope *gyroscope = Sensors::getGyroscope();
};

#endif // GYRO_H
