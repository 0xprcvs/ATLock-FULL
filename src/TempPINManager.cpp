#include "TempPINManager.h"

#include <cstring>

TempPINManager TempPINs;

// =====================================================

void TempPINManager::begin()
{
    for (uint8_t i = 0; i < MAX_TEMP_PINS; i++)
    {
        pins[i].active = false;
    }
}

// =====================================================

void TempPINManager::update()
{
    cleanupExpired();
}

// =====================================================

bool TempPINManager::add(const char* pin)
{
    for (uint8_t i = 0; i < MAX_TEMP_PINS; i++)
    {
        if (!pins[i].active)
        {
            strncpy(pins[i].pin, pin, 6);
            pins[i].pin[6] = '\0';

            pins[i].createdAt = millis();
            pins[i].active = true;

            return true;
        }
    }

    return false;
}

// =====================================================

bool TempPINManager::remove(const char* pin)
{
    for (uint8_t i = 0; i < MAX_TEMP_PINS; i++)
    {
        if (pins[i].active &&
            strcmp(pins[i].pin, pin) == 0)
        {
            pins[i].active = false;
            return true;
        }
    }

    return false;
}

// =====================================================

bool TempPINManager::exists(const char* pin)
{
    cleanupExpired();

    for (uint8_t i = 0; i < MAX_TEMP_PINS; i++)
    {
        if (pins[i].active &&
            strcmp(pins[i].pin, pin) == 0)
        {
            return true;
        }
    }

    return false;
}

// =====================================================

void TempPINManager::cleanupExpired()
{
    for (uint8_t i = 0; i < MAX_TEMP_PINS; i++)
    {
        if (pins[i].active)
        {
            if (millis() - pins[i].createdAt >= TEMP_PIN_LIFETIME)
            {
                pins[i].active = false;
            }
        }
    }
}