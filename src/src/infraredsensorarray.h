#ifndef BUILD_FOR_PC
#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H

class InfraredSensorArray {

public:
    InfraredSensorArray();

private:
    //Private class for 1 sensor
    class InfraredSensor {
    private:

    public:
        InfraredSensor();
    };

    InfraredSensor leftIR, centerIR, rightIR;
};

#endif // INFRAREDSENSORARRAY_H
#endif // BUILD_FOR_PC
