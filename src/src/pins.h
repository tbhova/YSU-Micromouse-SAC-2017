#ifndef PINS_H
#define PINS_H

//Digital Pins
const int   LEFT_MOTOR_SPEED        = 7,
            LEFT_MOTOR_FORWARD      = 9,
            LEFT_MOTOR_REVERSE      = 8,
            RIGHT_MOTOR_SPEED       = 10,
            RIGHT_MOTOR_FORWARD     = 11,
            RIGHT_MOTOR_REVERSE     = 12,
            MOTOR_STANDBY           = 24,
            RIGHT_MOTOR_ENCODER_A   = 27,
            RIGHT_MOTOR_ENCODER_B   = 28,
            LEFT_MOTOR_ENCODER_A    = 37,
            LEFT_MOTOR_ENCODER_B    = 38;

//Analog Input Pins
#define IR_SENSOR_LEFT      A13 //pin 32
#define IR_SENSOR_CENTER    A14 //pin 33
#define IR_SENSOR_RIGHT     A15 //pin 34

#endif // PINS_H
