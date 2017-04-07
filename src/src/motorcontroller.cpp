#include "motorcontroller.h"
#include <cmath>
#warning remove
#include "Arduino.h"
MotorController::MotorController() {
  reset();
  lastTime = millis();
}
void MotorController::reset(){
    velocityPID = PID(&velocityInput, &pwmOutput, &velocitySetPoint, 6.0, 0.38, 0.018,/*6.0, 0.38, 0.018,*/ DIRECT);
    pwmOutput = 0;
    velocityInput = 0;
    velocitySetPoint = 0;
    velocityPID.SetMode(MANUAL);
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
    //if(abs(actualVelocity - desiredVelocity) > 70){
      // velocityInput = desiredVelocity - 50;
    //}
    //else{
        this->velocityInput = actualVelocity;
    //}
    this->velocitySetPoint = desiredVelocity;
    if(millis() - lastTime > 100){
//        Serial.print("Velocity error:   ");
//        Serial.println(velocityInput - velocitySetPoint);
        lastTime = millis();
    }
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
