#include "encoders.h"
#include <Arduino.h>
#include "mk20dx128.h"
#include <Encoder.h>
#warning remove Arduino

Encoders::MouseEncoder::MouseEncoder(const int encoderA, const int encoderB) {
    lastTime = millis();
    encoder = new Encoder(encoderA, encoderB);
}

int Encoders::MouseEncoder::getSpeed() {
    const double delta = static_cast<double>(micros() - lastTime)/1000000.0;
    lastTime = micros();

    positionEstimate += velocityEstimate * delta;
    double positionError = getTicks() - positionEstimate;
    double velocityDerivative = (positionError - lastPositionError) * kd * delta;
    lastPositionError = positionError;
    velocityIntegrator += positionError * ki * delta;
    velocityEstimate = positionError * kp + velocityIntegrator + velocityDerivative;

    int ticksDelta = getTicks() - lastTicks;
    lastTicks = getTicks();
    if (ticksDelta < 0 != velocityEstimate < 0) {
        velocityIntegrator = 0;
        velocityEstimate = 0;
    }

    return static_cast<int>(velocityEstimate);
}

int Encoders::MouseEncoder::getTicks() {
    return encoder->read();
}

void Encoders::MouseEncoder::reset(int reset) {
    encoder->write(reset);
    positionEstimate = 0; velocityEstimate = 0; velocityIntegrator = 0;
    lastTime = micros();
}

Encoders::MouseEncoder::~MouseEncoder() {
    delete encoder;
}
