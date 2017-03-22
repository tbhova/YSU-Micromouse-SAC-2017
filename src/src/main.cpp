#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"


void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
        pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
        pinMode(LEFT_MOTOR_REVERSE, OUTPUT);
        pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
        pinMode(RIGHT_MOTOR_REVERSE, OUTPUT);
        pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
        pinMode(LEFT_MOTOR_SPEED, OUTPUT);
        pinMode(MOTOR_STANDBY, OUTPUT);
        pinMode(IR_SENSOR_LEFT, INPUT);
        pinMode(IR_SENSOR_CENTER, INPUT);
        pinMode(IR_SENSOR_RIGHT, INPUT);
        pinMode(LEFT_MOTOR_ENCODER_A, INPUT);
        pinMode(LEFT_MOTOR_ENCODER_B, INPUT);
        pinMode(RIGHT_MOTOR_ENCODER_A, INPUT);
        pinMode(RIGHT_MOTOR_ENCODER_B, INPUT);
        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_A), rightEncoderUpdate, RISING);
        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_A), rightEncoderUpdate, FALLING);
        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_B), rightEncoderUpdate, RISING);
        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_B), rightEncoderUpdate, FALLING);
        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_A), rightEncoderUpdate, RISING);
        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_A), rightEncoderUpdate, FALLING);
        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_B), rightEncoderUpdate, RISING);
        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_B), rightEncoderUpdate, FALLING);

}

void loop() {
        digitalWriteFast(LED_BUILTIN, HIGH);
        delay(3000);
        digitalWriteFast(LED_BUILTIN, LOW);
        delay(300);
        //Motors motors;
        //motors.setSpeed(128,-128);
        //delay(600);
        //motors.setSpeed(-128,128);

}
