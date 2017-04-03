#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include "encoders.h"
#include "motors.h"

extern "C"{
   int _getpid(){ return -1;}
   int _kill(int pid, int sig){ return -1; }
   int _write(){return -1;}
}
int distance=8000;
int motorSpeed=0;
int state=1;
Motors motor;
Encoders encoder;
const double wheelBase=95;
double circles=.125;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
    pinMode(LEFT_MOTOR_REVERSE, OUTPUT);
    pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_REVERSE, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED, OUTPUT);
    pinMode(MOTOR_STANDBY, OUTPUT);
    pinMode(IR_SENSOR_LEFT, INPUT_PULLDOWN);
    pinMode(IR_SENSOR_CENTER, INPUT_PULLDOWN);
    pinMode(IR_SENSOR_RIGHT, INPUT_PULLDOWN);
    Serial.begin(9600);
    while(!Serial);
}
double radTurn=25*wheelBase*(2*circles*3.4159265359);
void loop() {
    digitalWriteFast(LED_BUILTIN, HIGH);
    delay(30);
    digitalWriteFast(LED_BUILTIN, LOW);
    delay(30);

//    Serial.println(encoder.getRightTicks());
    motor.setSpeed(-170, 170);
    while(encoder.getRightTicks()<=radTurn) {
        motor.setSpeed(-170, 170);
    }
    motor.setSpeed(0,0);

//    if(state==1) {
//        motorSpeed++;
//        motor.setSpeed(-motorSpeed, motorSpeed);
//        if(motorSpeed == 130) {
//            state++;
//        }
//    }
//    if(state==2) {
//        if(distance-encoder.getLeftTicks() < 3000) {
//            state++;
//        }
//    }
//    if(state==3) {
//        motorSpeed--;
//        motor.setSpeed(-motorSpeed, motorSpeed);
//        if (motorSpeed == 0) state++;
//    }
//    if(state==4) {
//        Serial.begin(9600);
//        delay(500);
//        Serial.println(encoder.getLeftTicks());
//    }

}
