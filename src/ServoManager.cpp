#include "ServoManager.h"

#include "Pins.h"
#include "Config.h"

#include <ESP32Servo.h>

Servo servo;

ServoManager ServoMgr;

// =====================================================
// Initialize
// =====================================================

void ServoManager::begin()
{
    servo.setPeriodHertz(50);

    servo.attach(SERVO_PIN);

    lock();
}

// =====================================================

void ServoManager::update()
{
}

// =====================================================

void ServoManager::lock()
{
    servo.write(SERVO_LOCK_POSITION);

    angle = SERVO_LOCK_POSITION;

    locked = true;
}

// =====================================================

void ServoManager::unlock()
{
    servo.write(SERVO_UNLOCK_POSITION);

    angle = SERVO_UNLOCK_POSITION;

    locked = false;
}

// =====================================================

bool ServoManager::isLocked() const
{
    return locked;
}

// =====================================================

uint8_t ServoManager::currentAngle() const
{
    return angle;
}