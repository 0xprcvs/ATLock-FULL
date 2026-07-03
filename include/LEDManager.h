#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include <Arduino.h>

enum class LEDMode
{
    Off,
    Locked,
    Unlocked,
    Success,
    Error,
    Blink
};

class LEDManager
{
public:

    void begin();

    void update();

    void setMode(LEDMode mode);

    void off();

    void locked();

    void unlocked();

    void success();

    void error();

private:

    LEDMode currentMode = LEDMode::Off;

    unsigned long previousMillis = 0;

    bool blinkState = false;
};

extern LEDManager LEDs;

#endif