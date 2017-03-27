#include "encoders.h"
#include <Arduino.h>
#include "mk20dx128.h"
#include <Encoder.h>

Encoders::MouseEncoder::MouseEncoder(const int encoderA, const int encoderB) {
    lastTime = millis();
    encoder = new Encoder(encoderA, encoderB);
}

int Encoders::MouseEncoder::getSpeed() {
    int delta = static_cast<int>(millis() - lastTime);
    lastTime += static_cast<unsigned int>(delta);

    positionEstimate += velocityEstimate * delta;
    int positionError = getTicks() - positionEstimate;
    velocityIntegrator += positionError * kp * delta;
    velocityEstimate = positionError * kp + velocityIntegrator;

    return velocityEstimate;
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
