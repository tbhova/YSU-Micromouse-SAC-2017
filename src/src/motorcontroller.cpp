#include "motorcontroller.h"

MotorController::MotorController() {
 velocityPID.SetMode(AUTOMATIC);
}

int MotorController::getPWM(const int desiredVelocity, const int actualVelocity) {

    this->velocityInput = actualVelocity;
    this->velocitySetPoint = desiredVelocity;

    velocityPID.Compute();

    if(this->pwmOutput > 255){
        this->pwmOutput = 255;
    }
    else if(this->pwmOutput < -255){
        this->pwmOutput = -255;
    }
    return this->pwmOutput;
}
