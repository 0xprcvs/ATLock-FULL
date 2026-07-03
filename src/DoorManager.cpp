#include "DoorManager.h"

#include "Pins.h"
#include "Config.h"

#include <ESP32Servo.h>

Servo doorServo;

DoorManager Door;

void DoorManager::begin()
{
    doorServo.attach(SERVO_PIN);

    lock();
}

void DoorManager::update()
{
    if (!locked)
    {
        if (millis() - unlockTime >= AUTO_LOCK_TIME)
        {
            lock();
        }
    }
}

void DoorManager::lock()
{
    doorServo.write(SERVO_LOCK_POSITION);

    locked = true;
}

void DoorManager::unlock()
{
    doorServo.write(SERVO_UNLOCK_POSITION);

    unlockTime = millis();

    locked = false;
}

bool DoorManager::isLocked() const
{
    return locked;
}