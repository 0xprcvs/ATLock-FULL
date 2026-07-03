#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include <Arduino.h>

enum class AuthSource
{
    None,
    PIN,
    RFID,
    Dashboard,
    InsideButton
};

enum class AuthStatus
{
    Pending,
    Success,
    Failed,
    LockedOut
};

class AuthenticationManager
{
public:

    void begin();

    void update();

    void reset();

    bool authenticatePIN(const String& pin);

    bool authenticateCard(const String& uid);

    bool authenticateDashboard(
        const String& username,
        const String& password
    );

    void lockout();

    bool isLockedOut() const;

    uint8_t remainingAttempts() const;

private:

    uint8_t failedAttempts = 0;

    bool lockedOut = false;

    unsigned long lockoutStart = 0;

};

extern AuthenticationManager Auth;

#endif