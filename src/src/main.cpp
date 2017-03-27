#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include "encoders.h"
#include "motors.h"


Encoders encoders;

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

//    leftWheel = new Encoder(LEFT_MOTOR_ENCODER_A, LEFT_MOTOR_ENCODER_B);
//    rightWheel = new Encoder(RIGHT_MOTOR_ENCODER_A, RIGHT_MOTOR_ENCODER_B);

    Serial.begin(9600);

    while (!Serial) {

    }
    Serial.println("Two Encoder Test:");
    Serial.print("LeftEncoder: ");
    Serial.print(encoders.getLeftSpeed());
    Serial.print("RightEncoder: ");
    Serial.println(encoders.getRightSpeed());
    while (!Serial) {

    }
}

long positionLeft  = -999;
long positionRight = -999;
int motorSpeed = 0;
void loop() {
        digitalWriteFast(LED_BUILTIN, HIGH);
        delay(3000);
        digitalWriteFast(LED_BUILTIN, LOW);
        delay(300);
        Motors motors;
        //motors.setSpeed(128,-128);
        //delay(600);

        motors.setSpeed(motorSpeed, 0);

        for(int i=0; i<100; i++) {
        Serial.println("Two Encoder Test:");
        Serial.print("LeftEncoder: ");
        Serial.print(encoders.getLeftSpeed());
        Serial.print("RightEncoder: ");
        Serial.print(encoders.getRightSpeed());
        Serial.println(motorSpeed);
        delay(100);
        }
        motorSpeed+=50;
        motorSpeed= motorSpeed % 256;



          // if a character is sent from the serial monitor,
          // reset both back to zero.
          if (Serial.available()) {
            Serial.read();
            Serial.println("Reset both wheels to zero");
            encoders.reset(0);
          }

}
