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

    Serial.begin(9600);

//    while (!Serial);
}

void loop() {
    digitalWriteFast(LED_BUILTIN, HIGH);
    delay(300);
    digitalWriteFast(LED_BUILTIN, LOW);
    delay(300);
}
