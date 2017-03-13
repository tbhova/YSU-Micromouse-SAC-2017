#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H


class InfraredSensorArray {

public:
    InfraredSensorArray();
    unsigned short int getLeftIR();
    unsigned short int getRightIR();
    unsigned short int getCenterIR();
    unsigned short int* getIRData();


private:
    //Private class for 1 sensor
    class InfraredSensor {

    public:
        InfraredSensor();
        short int getDistance();
    };


    InfraredSensor leftIR, centerIR, rightIR;
};

#endif // INFRAREDSENSORARRAY_H
