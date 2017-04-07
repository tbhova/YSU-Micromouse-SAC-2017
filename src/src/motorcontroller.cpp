#include "motorcontroller.h"

MotorController::MotorController() {
 velocityPID.SetMode(AUTOMATIC);
 velocityPID.SetOutputLimits(-255, 255);
 velocityPID.SetSampleTime(3);
}

int MotorController::getPWM(const int desiredVelocity, const int actualVelocity) {

    this->velocityInput = actualVelocity;
    this->velocitySetPoint = desiredVelocity;

    velocityPID.Compute();

    /*if(this->pwmOutput > 255){
        return 255;
    }
    else if(this->pwmOutput < -255){
        return -255;
    }*/
    return this->pwmOutput;
}
