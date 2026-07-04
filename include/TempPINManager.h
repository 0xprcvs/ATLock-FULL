#ifndef TEMPPINMANAGER_H
#define TEMPPINMANAGER_H

#include <Arduino.h>

constexpr uint8_t MAX_TEMP_PINS = 5;
constexpr uint32_t TEMP_PIN_LIFETIME = 86400000UL; // 24 hours

struct TemporaryPIN
{
    char pin[7];              // 6 digits + null terminator
    unsigned long createdAt;
    bool active;
};

class TempPINManager
{
public:

    void begin();

    void update();

    bool add(const char* pin);

    bool remove(const char* pin);

    bool exists(const char* pin);

    void cleanupExpired();

private:

    TemporaryPIN pins[MAX_TEMP_PINS];
};

extern TempPINManager TempPINs;

#endif