#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H

#include "interpolateir.h"
#include "pins.h"

class InfraredSensorArray {
public:
    InfraredSensorArray();
    ~InfraredSensorArray();
    unsigned short int getLeftDistance() const;
    unsigned short int getRightDistance() const;
    unsigned short int getCenterDistance() const;


private:
    class InfraredSensor {
    public:
        InfraredSensor(int pin, InterpolateIR* interpolate); //save pin and interpolate object
        unsigned short int getDistance() const;
    private:
        int pin;
        InterpolateIR* interpolate;
    };

    InterpolateIR interpolate;  //this needs passed to each of the L R C IR sensors
    InfraredSensor leftIR = InfraredSensor(IR_SENSOR_LEFT, &interpolate);
    InfraredSensor centerIR = InfraredSensor(IR_SENSOR_CENTER, &interpolate);
    InfraredSensor rightIR = InfraredSensor(IR_SENSOR_RIGHT, &interpolate);
};

#endif // INFRAREDSENSORARRAY_H
