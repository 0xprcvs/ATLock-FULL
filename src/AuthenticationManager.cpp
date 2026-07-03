#include "AuthenticationManager.h"

#include "LoggerManager.h"
#include "DoorManager.h"
#include "Config.h"

AuthenticationManager Auth;

// Temporary Admin PIN
// Later this will come from Preferences/NVS.
static const String ADMIN_PIN = "1234";

// =====================================================

void AuthenticationManager::begin()
{
    reset();
}

// =====================================================

void AuthenticationManager::update()
{
    if (lockedOut)
    {
        if (millis() - lockoutStart >= LOCKOUT_TIME)
        {
            lockedOut = false;
            failedAttempts = 0;
        }
    }
}

// =====================================================

void AuthenticationManager::reset()
{
    failedAttempts = 0;
    lockedOut = false;
}

// =====================================================

bool AuthenticationManager::authenticatePIN(const String& pin)
{
    if (lockedOut)
        return false;

    if (pin == ADMIN_PIN)
{
    failedAttempts = 0;

    Logger.log(
        LogLevel::Info,
        "PIN accepted"
    );

    Door.unlock();

    return true;
}

    Logger.log(
    LogLevel::Warning,
    "Invalid PIN"
);

failedAttempts++;

    if (failedAttempts >= MAX_PIN_ATTEMPTS)
    {
        Logger.log(
    LogLevel::Error,
    "Too many failed PIN attempts"
);

lockout();
    }

    return false;
}

// =====================================================

bool AuthenticationManager::authenticateCard(const String& uid)
{
    (void)uid;

    return false;
}

// =====================================================

bool AuthenticationManager::authenticateDashboard(
    const String& username,
    const String& password)
{
    (void)username;
    (void)password;

    return false;
}

// =====================================================

void AuthenticationManager::lockout()
{
    lockedOut = true;

    lockoutStart = millis();
}

// =====================================================

bool AuthenticationManager::isLockedOut() const
{
    return lockedOut;
}

// =====================================================

uint8_t AuthenticationManager::remainingAttempts() const
{
    if (failedAttempts >= MAX_PIN_ATTEMPTS)
        return 0;

    return MAX_PIN_ATTEMPTS - failedAttempts;
}