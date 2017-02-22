#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H


class InfraredSensorArray {

public:
    InfraredSensorArray();

private:
    //Private class for 1 sensor
    class InfraredSensor {
    private:
        // Priavate class to interpolate voltages to distances
        class InterpolateIR {
            struct IR_Data {

            };
        };

    public:
        InfraredSensor();
    };

    InfraredSensor leftIR, centerIR, rightIR;
};

#endif // INFRAREDSENSORARRAY_H
