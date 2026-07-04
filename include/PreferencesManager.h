#ifndef PREFERENCESMANAGER_H
#define PREFERENCESMANAGER_H

#include <Arduino.h>

class PreferencesManager
{
public:

    void begin();

    // Admin PIN
    String getAdminPIN() const;
    void setAdminPIN(const String& pin);

    // Auto Lock
    uint32_t getAutoLockTime() const;
    void setAutoLockTime(uint32_t seconds);

    // Display
    uint8_t getBrightness() const;
    void setBrightness(uint8_t value);

    // Sound
    uint8_t getBuzzerVolume() const;
    void setBuzzerVolume(uint8_t value);

private:

    String adminPIN = "1234";

    uint32_t autoLockTime = 5;

    uint8_t brightness = 100;

    uint8_t buzzerVolume = 100;
};

extern PreferencesManager PreferencesMgr;

#endif