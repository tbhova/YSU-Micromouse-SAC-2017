#include "encoders.h"

Encoders::Encoders() {

}

void Encoders::reset(int reset) {
    leftEncoder.reset(reset);
    rightEncoder.reset(reset);
}
int Encoders::getLeftSpeed() {
    return leftEncoder.getSpeed();
}

int Encoders::getRightSpeed() {
    return rightEncoder.getSpeed();
}

int Encoders::getLeftTicks() {
    return leftEncoder.getTicks();
}

int Encoders::getRightTicks() {
    return rightEncoder.getTicks();
}
