#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include <Encoder.h>


Encoder * leftWheel/*(LEFT_MOTOR_ENCODER_A, LEFT_MOTOR_ENCODER_B)*/;
Encoder * rightWheel/*(RIGHT_MOTOR_ENCODER_A, RIGHT_MOTOR_ENCODER_B)*/;


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
//        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_A), rightEncoderUpdate, RISING);
//        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_A), rightEncoderUpdate, FALLING);
//        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_B), rightEncoderUpdate, RISING);
//        attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_B), rightEncoderUpdate, FALLING);
//        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_A), rightEncoderUpdate, RISING);
//        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_A), rightEncoderUpdate, FALLING);
//        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_B), rightEncoderUpdate, RISING);
//        attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_B), rightEncoderUpdate, FALLING);

    leftWheel = new Encoder(LEFT_MOTOR_ENCODER_A, LEFT_MOTOR_ENCODER_B);
    rightWheel = new Encoder(RIGHT_MOTOR_ENCODER_A, RIGHT_MOTOR_ENCODER_B);

    Serial.begin(9600);

    while (!Serial) {

    }
    Serial.println("TwoKnobs Encoder Test:");
    leftWheel = new Encoder(LEFT_MOTOR_ENCODER_A, LEFT_MOTOR_ENCODER_B);
    rightWheel = new Encoder(RIGHT_MOTOR_ENCODER_A, RIGHT_MOTOR_ENCODER_B);
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
        digitalWriteFast(LED_BUILTIN, HIGH);
        delay(3000);
        digitalWriteFast(LED_BUILTIN, LOW);
        delay(300);
        //Motors motors;
        //motors.setSpeed(128,-128);
        //delay(600);
        //motors.setSpeed(-128,128);


        long newLeft, newRight;
          newLeft = leftWheel->read();
          newRight = rightWheel->read();
         if (newLeft != positionLeft || newRight != positionRight) {
            Serial.print("Left = ");
            Serial.print(newLeft);
            Serial.print(", Right = ");
            Serial.print(newRight);
            Serial.println();
            positionLeft = newLeft;
            positionRight = newRight;
          }
          // if a character is sent from the serial monitor,
          // reset both back to zero.
          if (Serial.available()) {
            Serial.read();
            Serial.println("Reset both wheels to zero");
            leftWheel->write(0);
            rightWheel->write(0);
          }

}
