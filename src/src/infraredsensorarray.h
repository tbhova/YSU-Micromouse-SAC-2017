#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H

class InfraredSensorArray {
public:
    unsigned short int getLeftDistance() const;
    unsigned short int getRightDistance() const;
    unsigned short int getCenterDistance() const;

private:
    class InfraredSensor {
    public:
        InfraredSensor(int pin, InterpolateIR interpolate); //save pin and interpolate object
        unsigned short int getDistance() const;
    };

    InterpolateIR interpolate;  //this needs passed to each of the L R C IR sensors
    InfraredSensor leftIR, rightIR, centerIR = IRSensor(CENTER_IR_PIN);

};

#endif // INFRAREDSENSORARRAY_H
