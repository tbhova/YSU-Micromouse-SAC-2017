#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include "navigator.h"

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
//    while(!Serial);
}

void loop() {
    digitalWriteFast(LED_BUILTIN, HIGH);


//    navigator.run();
//    navigator.driveStraight();
//    navigator.driveStraightIndividualCells();
//    navigator.turnRepeatedly();
    Serial.println("Begin");
    navigator.driveStupidMaze();

    /*bool leftWalls[12];
    bool rightWalls[12];*/
    /*for(int i=0; i<12; i++){
        //driver.drive(North);
        hardwareManager.drive(180, 0);
        leftWalls[i] = hardwareManager.isLeftWall();
        rightWalls[i] = hardwareManager.isRightWall();
    }*/

    /*while(true){
        for(int i=0; i<12; i++){
           Serial.print("Left wall/rightwall: ");
           Serial.print(i);
           Serial.print("   ");
           Serial.print(leftWalls[i]);
           Serial.print(",");
           Serial.println(rightWalls[i]);
           delay(500);
        }
        delay(1000);
    }*/

    digitalWriteFast(LED_BUILTIN, LOW);
    delay(2000);
}
