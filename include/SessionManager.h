#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <Arduino.h>

enum class SessionMode
{
    Home,
    EnterPIN,
    Admin,
    RFIDEnroll,
    WiFiSetup
};

class SessionManager
{
public:

    void begin();

    void update();

    void setMode(SessionMode mode);

    SessionMode mode() const;

    bool is(SessionMode mode) const;

private:

    SessionMode currentMode = SessionMode::Home;
};

extern SessionManager Session;

#endif