#include "DoorManager.h"
#include "LoggerManager.h"
#include "ServoManager.h"
#include "LEDManager.h"
#include "SoundManager.h"
#include "StateManager.h"
#include "Globals.h"
#include "Config.h"
#include "DisplayManager.h"

DoorManager Door;

// =====================================================
// Initialize
// =====================================================

void DoorManager::begin()
{
    ServoMgr.begin();

    LEDs.begin();

    Speaker.begin();

    lock();
}

// =====================================================
// Update
// =====================================================

void DoorManager::update()
{
    ServoMgr.update();

    LEDs.update();

    Speaker.update();

    if (!locked)
    {
        if (millis() - unlockTime >= AUTO_LOCK_TIME)
        {
            lock();
        }
    }
}

// =====================================================
// Lock Door
// =====================================================

void DoorManager::lock()
{
    if (locked)
    return;
    ServoMgr.lock();

    LEDs.locked();

    Speaker.play(Sound::Lock);

    State.setState(SystemState::Home);
    Display.showHomeScreen();

    locked = true;
    
    Logger.log(
    LogLevel::Info,
    "Door locked"
);
}

// =====================================================
// Unlock Door
// =====================================================

void DoorManager::unlock()
{
    if (!locked)
    return;

    ServoMgr.unlock();

    LEDs.unlocked();

    Speaker.play(Sound::Unlock);

    State.setState(SystemState::Granted);
    Display.showUnlockedScreen();

    unlockTime = millis();

    locked = false;

    Logger.log(
    LogLevel::Info,
    "Door unlocked"
);
}

// =====================================================

bool DoorManager::isLocked() const
{
    return locked;
}