#include "SessionManager.h"

SessionManager Session;

void SessionManager::begin()
{
    currentMode = SessionMode::Home;
}

void SessionManager::update()
{
}

void SessionManager::setMode(SessionMode mode)
{
    currentMode = mode;
}

SessionMode SessionManager::mode() const
{
    return currentMode;
}

bool SessionManager::is(SessionMode mode) const
{
    return currentMode == mode;
}