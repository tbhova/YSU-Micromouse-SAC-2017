#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H

class InfraredSensorArray {

public:
    InfraredSensorArray();
    short int getLeftIR();
    short int getRightIR();
    short int getCenterIR();

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
