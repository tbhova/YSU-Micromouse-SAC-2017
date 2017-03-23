#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H

class InfraredSensorArray {

public:
    InfraredSensorArray();
    unsigned short int getLeftIR() const;
    unsigned short int getRightIR() const;
    unsigned short int getCenterIR() const;

private:
    //Private class for 1 sensor
    class InfraredSensor {
    private:

    public:
        InfraredSensor();
        unsigned short int getDistance() const;
    };

    InfraredSensor leftIR, centerIR, rightIR;
};

#endif // INFRAREDSENSORARRAY_H
