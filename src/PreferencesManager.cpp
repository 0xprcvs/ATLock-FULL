#include "PreferencesManager.h"

PreferencesManager PreferencesMgr;

// =====================================================

void PreferencesManager::begin()
{
}

// =====================================================
// Admin PIN
// =====================================================

String PreferencesManager::getAdminPIN() const
{
    return adminPIN;
}

void PreferencesManager::setAdminPIN(const String& pin)
{
    adminPIN = pin;
}

// =====================================================
// Auto Lock
// =====================================================

uint32_t PreferencesManager::getAutoLockTime() const
{
    return autoLockTime;
}

void PreferencesManager::setAutoLockTime(uint32_t seconds)
{
    autoLockTime = seconds;
}

// =====================================================
// Display
// =====================================================

uint8_t PreferencesManager::getBrightness() const
{
    return brightness;
}

void PreferencesManager::setBrightness(uint8_t value)
{
    brightness = value;
}

// =====================================================
// Sound
// =====================================================

uint8_t PreferencesManager::getBuzzerVolume() const
{
    return buzzerVolume;
}

void PreferencesManager::setBuzzerVolume(uint8_t value)
{
    buzzerVolume = value;
}