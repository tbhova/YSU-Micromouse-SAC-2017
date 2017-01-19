#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H


class InfraredSensorArray {

public:
    InfraredSensorArray();

private:
    //Private class for 1 sensor
    class InfraredSensor {
    public:
        InfraredSensor();
    };

    InfraredSensor leftIR, centerIR, rightIR;
};

#endif // INFRAREDSENSORARRAY_H
