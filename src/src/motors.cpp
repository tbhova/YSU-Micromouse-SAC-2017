#include "motors.h"
#include "mk20dx128.h"

Motors::Motors()
{
    this->stop();
}

void Motors::driveForward() {
    leftForward();
    rightForward();
}

void Motors::turn() {
    rightForward();
    leftReverse();
}

void Motors::stop() {
    rightStop();
    leftStop();
}

void Motors::leftForward() {
    digitalWrite(Left_Motor_Reverse, LOW);
    digitalWrite(Left_Motor_Forward, HIGH);
    analogWrite(Left_Motor_Speed, power);
}

void Motors::leftStop() {
    digitalWrite(Left_Motor_Forward, LOW);
    digitalWrite(Left_Motor_Reverse, LOW);
    analogWrite(Left_Motor_Speed, off);
}

void Motors::leftReverse() {
    digitalWrite(Left_Motor_Forward, LOW);
    digitalWrite(Left_Motor_Reverse, HIGH);
    analogWrite(Left_Motor_Speed, power);
}

void Motors::rightForward() {
    digitalWrite(Right_Motor_Reverse, LOW);
    digitalWrite(Right_Motor_Forward, HIGH);
    analogWrite(Right_Motor_Speed, power);
}

void Motors::rightReverse() {
    digitalWrite(Right_Motor_Forward, LOW);
    digitalWrite(Right_Motor_Reverse, HIGH);
    analogWrite(Right_Motor_Speed, power);
}

void Motors::rightStop() {
    digitalWrite(Right_Motor_Reverse, LOW);
    digitalWrite(Right_Motor_Forward, LOW);
    analogWrite(Right_Motor_Speed, off);
}
