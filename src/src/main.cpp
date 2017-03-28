#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include "infraredsensorarray.h"

//#include "motors.h"
extern "C"{
   int _getpid(){ return -1;}
   int _kill(int pid, int sig){ return -1; }
   int _write(){return -1;}
}
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
        Serial.println("IR Sensor Test");

}

void loop() {

        InfraredSensorArray irSensor;
        digitalWriteFast(LED_BUILTIN, HIGH);
        delay(300);
        digitalWriteFast(LED_BUILTIN, LOW);
        delay(300);
        Serial.print("Left Distance: ");
        Serial.print(irSensor.getLeftDistance());
        Serial.print(" Center Distance: ");
        Serial.print(irSensor.getCenterDistance());
        Serial.print(" Right Distance: ");
        Serial.println(irSensor.getRightDistance());
}
