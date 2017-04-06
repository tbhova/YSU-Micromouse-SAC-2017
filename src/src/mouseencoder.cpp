#include "encoders.h"
#include <Arduino.h>
#include "mk20dx128.h"
#include <Encoder.h>
#warning remove
#include "Arduino.h"
Encoders::MouseEncoder::MouseEncoder(const int encoderA, const int encoderB) {
    lastTime = millis();
    count = 100;
    encoder = new Encoder(encoderA, encoderB);
}

int Encoders::MouseEncoder::getSpeed() {


    unsigned int delta = millis() - lastTime;
    lastTime += delta;
    double deltaDouble = static_cast<double>(delta)/1000.0;

    positionEstimate += velocityEstimate * deltaDouble;
    double positionError = getTicks() - positionEstimate;
    if(count < 40){
        velocityIntegrator += positionError * 30.0 * deltaDouble;
        velocityEstimate = positionError * 2.0 + velocityIntegrator;
        count++;
    }
    else{
        velocityIntegrator += positionError * ki * deltaDouble;
        velocityEstimate = positionError * kp + velocityIntegrator;
    }

#warning remove

    return static_cast<int>(velocityEstimate);
}

int Encoders::MouseEncoder::getTicks() {
    return encoder->read();
}

void Encoders::MouseEncoder::reset(int reset) {
    encoder->write(reset);
    count = 0;
    positionEstimate = 0; velocityEstimate = 0; velocityIntegrator = 0;
    lastTime = millis();
}

Encoders::MouseEncoder::~MouseEncoder() {
    delete encoder;
}
