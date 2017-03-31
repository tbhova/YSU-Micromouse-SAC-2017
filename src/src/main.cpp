#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"
#include "pins.h"
#include "infraredsensorarray.h"

//#include "motors.h"

// Begin PID test code
#include <PID_v1.h>
#include <PID_AutoTune_v0.h>

byte ATuneModeRemember=2;
double input=80, output=50, setpoint=180;
double kp=2,ki=0.5,kd=2;

double kpmodel=1.5, taup=100, theta[50];
double outputStart=5;
double aTuneStep=50, aTuneNoise=1, aTuneStartValue=100;
unsigned int aTuneLookBack=20;

boolean tuning = false;
unsigned long  modelTime, serialTime;

PID myPID(&input, &output, &setpoint,kp,ki,kd, DIRECT);
PID_ATune aTune(&input, &output);
// End PID test code

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
        //while(!Serial);
}

void loop() {
        digitalWriteFast(LED_BUILTIN, HIGH);
        delay(300);
        digitalWriteFast(LED_BUILTIN, LOW);
        delay(300);

}
