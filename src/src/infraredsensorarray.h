#ifndef INFRAREDSENSORARRAY_H
#define INFRAREDSENSORARRAY_H

// new class
class InfaredSensorArray {
public:
    //repeat for all sensors
    short int getLeftDistance() {
        leftIR.getDistance();
    }

    short int getRightDistance() {
        rightIR.getDistance();
    }

    short int getCenterDistance() {
        centerIR.getDistance()
    }

private:
    InterpolateIR interpolate;  //this needs passed to each of the L R C IR sensors
    InfraredSensor leftIR, rightIR, centerIR = IRSensor(CENTER_IR_PIN);
}

InfraredSensor {
public:
        InfraredSensor(int pin, InterpolateIR interpolate); //save pin and interpolate object
        short int getDistance() {
            int voltage = analogRead(CENTER_IR_PIN);
            int distance = interpolate.getDistance(voltage);
            return distance;
        }
};

#endif // INFRAREDSENSORARRAY_H
//Note Interpolate IR is already done
