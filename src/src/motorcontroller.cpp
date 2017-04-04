#include "motorcontroller.h"

MotorController::MotorController() {
 velocityPID.SetMode(AUTOMATIC);
 velocityPID.SetOutputLimits(-255, 255);
 velocityPID.SetSampleTime(3);
 velocityATune.SetOutputStep(70);
 velocityATune.SetNoiseBand(100);
 velocityATune.SetControlType(1);
 velocityATune.SetLookbackSec(1);
 doneAuto = false;
}

int MotorController::getPWM(const int desiredVelocity, const int actualVelocity) {

    this->velocityInput = actualVelocity;
    this->velocitySetPoint = desiredVelocity;

    velocityPID.Compute();

    return this->pwmOutput;
}
int MotorController::autoTune(const int actualVelocity){
   //bool done = false;
  // this->getPWM(3000, actualVelocity);
   this->velocityInput = actualVelocity;
   if(velocityATune.Runtime() != 0){
       velocityPID.SetTunings(velocityATune.GetKp(),
                              velocityATune.GetKi(), velocityATune.GetKd());
        this->doneAuto = true;
   }
    return this->pwmOutput;
}
