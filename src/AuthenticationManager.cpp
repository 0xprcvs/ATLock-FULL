#include "AuthenticationManager.h"
#include "TempPINManager.h"
#include "LoggerManager.h"
#include "DoorManager.h"
#include "Config.h"
#include "PreferencesManager.h"
#include "UserManager.h"
AuthenticationManager Auth;

// Temporary Admin PIN
// Later this will come from Preferences/NVS.


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

            Logger.log(
             LogLevel::Info,
             "PIN lockout ended"
                        );
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
{
    Logger.log(
        LogLevel::Warning,
        "PIN attempt while locked out"
    );

    return false;
}

  // Admin PIN (currently 4 digits)
User* user = Users.findByPIN(pin.c_str());

if (user != nullptr)
{
    failedAttempts = 0;

    Users.login(user);

    Logger.log(
        LogLevel::Info,
        String(user->username) + " authenticated via PIN"
    );

    Door.unlock();

    return true;
}

// Temporary PIN (6 digits)
// TODO: Implement in v0.2.2
else if (pin.length() == 6)
{
    Logger.log(
        LogLevel::Info,
        "Temporary PIN authentication not implemented"
    );
}

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