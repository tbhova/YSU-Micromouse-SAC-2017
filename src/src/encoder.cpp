#include "encoders.h"
#include <Arduino.h>
#include "mk20dx128.h"

Encoders::Encoder::Encoder() {
    lastTime = micros();
}

int Encoders::Encoder::getSpeed() {
    int delta = static_cast<int>(micros() - lastTime);
    lastTime += static_cast<unsigned int>(delta);

    positionEstimate += velocityEstimate * delta;
    int positionError = getTicks() - positionEstimate;
    velocityIntegrator += positionError * kp * delta;
    velocityEstimate = positionError * kp + velocityIntegrator;

    return velocityEstimate;
}

int Encoders::Encoder::getTicks() {
    return 0;
}
