#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"

void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
        digitalWriteFast(LED_BUILTIN, HIGH);
        delay(300);
        digitalWriteFast(LED_BUILTIN, LOW);
        delay(3000);
}
