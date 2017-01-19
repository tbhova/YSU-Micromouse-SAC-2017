#ifndef PINS_H
#define PINS_H

//Digital Pins
const int   LEFT_MOTOR_FORWARD      = 5,
            LEFT_MOTOR_REVERSE      = 6,
            RIGHT_MOTOR_FORWARD     = 7,
            RIGHT_MOTOR_REVERSE     = 8,
            LEFT_MOTOR_SPEED        = 9,
            RIGHT_MOTOR_SPEED       = 10,
            LEFT_MOTOR_ENCODER_A    = 37,
            LEFT_MOTOR_ENCODER_B    = 38,
            RIGHT_MOTOR_ENCODER_A   = 27,
            RIGHT_MOTOR_ENCODER_B   = 28;

//Analog Input Pins
#define IR_SENSOR_LEFT      A13 //pin 32
#define IR_SENSOR_CENTER    A14 //pin 33
#define IR_SENSOR_RIGHT     A15 //pin 34


#endif // PINS_H
