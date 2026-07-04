#include "LEDManager.h"

#include "Pins.h"

LEDManager LEDs;

void LEDManager::begin()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    locked();
}

void LEDManager::update()
{
}

void LEDManager::setMode(LEDMode mode)
{
    switch (mode)
    {
        case LEDMode::Off:
            off();
            break;

        case LEDMode::Locked:
            locked();
            break;

        case LEDMode::Unlocked:
            unlocked();
            break;
    }
}

void LEDManager::off()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    currentMode = LEDMode::Off;
}

void LEDManager::locked()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    currentMode = LEDMode::Locked;
}

void LEDManager::unlocked()
{
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    currentMode = LEDMode::Unlocked;
}

void LEDManager::success()
{
    unlocked();
}

void LEDManager::error()
{
    locked();
}