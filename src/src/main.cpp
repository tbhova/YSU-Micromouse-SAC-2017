#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include "navigator.h"

//#include "motorcontroller.h"
//#include "encoders.h"
//#include "motors.h"
//// Begin PID test code
//#include <PID_v1.h>
//#include <PID_AutoTune_v0.h>

//MotorController leftMotorController;
//MotorController rightMotorController;
//Encoders encoders;
//Motors motors;

extern "C"{
   int _getpid(){ return -1;}
   int _kill(int pid, int sig){ return -1; }
   int _write(){return -1;}
}

Navigator navigator;

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
    //while(!Serial);
}

void loop() {
    digitalWriteFast(LED_BUILTIN, HIGH);
    navigator.run();
    digitalWriteFast(LED_BUILTIN, LOW);

//    int leftSpeed;
//    //leftSpeed = leftMotorController.getPWM(3000, encoders.getLeftSpeed());
//    int rightSpeed;
//    //rightSpeed = rightMotorController.getPWM(3000, encoders.getRightSpeed());
//    leftSpeed = leftMotorController.autoTune(encoders.getLeftSpeed());
//    //rightSpeed = rightMotorController.autoTune(encoders.getRightSpeed());
//    if(leftMotorController.isAutoDone()){
//        motors.setSpeed(0, 0);
//        while(1){
//           Serial.print("Kp: ");
//           Serial.println(leftMotorController.getKp());
//           Serial.print("Ki: ");
//           Serial.println(leftMotorController.getKi());
//           Serial.print("Kd :");
//           Serial.println(leftMotorController.getKd());
//           delay(1000);
//       }
//    }
//    /*Serial.print("Left: ");
//    Serial.print(leftSpeed);
//    Serial.print("    ");
//    Serial.print(encoders.getLeftSpeed());
//    Serial.print("Right: ");
//    Serial.print(rightSpeed);
//    Serial.print("  ");
//    Serial.println(encoders.getRightSpeed());*/

//    motors.setSpeed(leftSpeed, leftSpeed);
//   // delay(1);
}
