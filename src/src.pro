win32 {
    HOMEDIR += $$(USERPROFILE)
}
else {
    HOMEDIR += $$(HOME)
}

INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\cores\teensy3"
INCLUDEPATH += "$${HOMEDIR}\workspace\YSU-Micromouse-SAC-2017\src\src"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\ADC"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\AccelStepper"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_CC3000"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_CC3000\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_GFX"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_ILI9340"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_ILI9341"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_NeoPixel"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_RA8875"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_SSD1306"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_ST7735"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_STMPE610"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_VS1053"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_nRF8001"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Adafruit_nRF8001\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\AltSoftSerial"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Artnet"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Audio"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Audio\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Bounce"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Bounce2"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\CapacitiveSensor"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\DS1307RTC"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\DmxSimple"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\DogLcd"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\EEPROM"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Encoder"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Encoder\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Entropy"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Ethernet"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FastCRC"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FastLED"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FlexCAN"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FlexiTimer2"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FreqCount"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FreqMeasure"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FreqMeasureMulti"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\FrequencyTimer2"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\ILI9341_t3"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\IRremote"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Keypad"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Keypad\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\LedControl\src"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\LedDisplay"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\LiquidCrystal"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\LiquidCrystalFast"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\LowPower"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\MFRC522"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\MIDI"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Metro"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\MsTimer2"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\NXPMotionSense"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\NXPMotionSense\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\NewPing"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\OSC"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\OctoWS2811"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\OneWire"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\PS2Keyboard"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\PS2Keyboard\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\PWMServo"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Ping"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\PulsePosition"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\RA8875"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\RadioHead"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SD"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SD\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SPI"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SPIFlash"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\ST7565"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SerialFlash"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Servo"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\ShiftPWM"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Snooze"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Snooze\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SoftPWM"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\SoftwareSerial"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\TFT_ILI9163C"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Talkie"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Time"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\TimeAlarms"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\TimerOne"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\TimerThree"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\TinyGPS"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Tlc5940"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\TouchScreen"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\UTFT"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\VirtualWire"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Wire"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\Wire\utility"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\XBee"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\XPT2046_Touchscreen"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\i2c_t3"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\ks0108"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\openGLCD"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\ssd1351"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\framework-arduinoteensy\libraries\x10"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\toolchain-gccarmnoneeabi\arm-none-eabi\include"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\toolchain-gccarmnoneeabi\lib\gcc\arm-none-eabi\4.8.4\include"
INCLUDEPATH += "$${HOMEDIR}\.platformio\packages\toolchain-gccarmnoneeabi\lib\gcc\arm-none-eabi\4.8.4\include-fixed"

DEFINES += "F_CPU=120000000L"
DEFINES += "LAYOUT_US_ENGLISH"
DEFINES += "PLATFORMIO=030100"
DEFINES += "__MK64FX512__"
DEFINES += "TEENSY35"
DEFINES += "USB_SERIAL"
DEFINES += "ARDUINO=10600"
DEFINES += "TEENSYDUINO=130"

OTHER_FILES += platformio.ini

SOURCES += \
    src/main.cpp \
    src/maze.cpp \
    src/stopgodriver.cpp \
    src/breadthfirstgps.cpp \
    src/infraredsensor.cpp \
    src/infraredsensorarray.cpp \
    src/motors.cpp \
    src/motor.cpp \
    src/encoders.cpp \
    src/navigator.cpp \
    src/interpolateir.cpp \
    src/hardwaremanager.cpp \
    src/batterysensor.cpp \
    src/driver.cpp \
    src/mouseencoder.cpp \
    src/wallcontroller.cpp \
    src/distancecontroller.cpp \
    src/anglecontroller.cpp \
    src/angledistancecontroller.cpp \
    src/wallcontroller.cpp \
    src/wallcontroller.cpp \
    src/motorcontroller.cpp

HEADERS += \
    src/maze.h \
    src/cardinal8.h \
    src/pins.h \
    src/navigator.h \
    src/driver.h \
    src/stopgodriver.h \
    src/gps.h \
    src/breadthfirstgps.h \
    src/infraredsensorarray.h \
    src/motors.h \
    src/encoders.h \
    src/coordinate.h \
    src/abstractdriver.h \
    src/interpolateir.h \
    src/hardwaremanager.h \
    src/batterysensor.h \
    src/stopgodriver.h \
    src/abstractdriver.h \
    src/abstracthardwaremanager.h \
    src/differentialdrivevelocity.h \
    src/wallcontroller.h \
    src/distancecontroller.h \
    src/anglecontroller.h \
    src/angledistancecontroller.h \
    src/wallcontroller.h \
    src/motorcontroller.h
