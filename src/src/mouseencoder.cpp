#include "encoders.h"
#include <Arduino.h>
#include "mk20dx128.h"
#include <Encoder.h>

Encoders::MouseEncoder::MouseEncoder(const int encoderA, const int encoderB) {
    lastTime = millis();
    encoder = new Encoder(encoderA, encoderB);
}

int Encoders::MouseEncoder::getSpeed() {
    unsigned int delta = millis() - lastTime;
    lastTime += delta;
    double deltaDouble = static_cast<double>(delta)/1000.0;

    positionEstimate += velocityEstimate * deltaDouble;
    double positionError = getTicks() - positionEstimate;
    velocityIntegrator += positionError * ki * deltaDouble;
    velocityEstimate = positionError * kp + velocityIntegrator;

    return static_cast<int>(velocityEstimate);
}

int Encoders::MouseEncoder::getTicks() {
    return encoder->read();
}

void Encoders::MouseEncoder::reset(int reset) {
    encoder->write(reset);
}

Encoders::MouseEncoder::~MouseEncoder() {
    delete encoder;
}
