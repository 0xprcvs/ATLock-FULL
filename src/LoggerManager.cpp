#include "LoggerManager.h"

LoggerManager Logger;

// =====================================================

void LoggerManager::begin()
{
    clear();
}

// =====================================================

void LoggerManager::update()
{
}

// =====================================================

void LoggerManager::clear()
{
    logCount = 0;
}

// =====================================================

void LoggerManager::log(
    LogLevel level,
    const String& message)
{
    if(logCount >= MAX_LOGS)
        return;

    logs[logCount].timestamp = millis();
    logs[logCount].level = level;
    logs[logCount].message = message;

    logCount++;

    Serial.print("[LOG] ");
    Serial.println(message);
}

// =====================================================

uint16_t LoggerManager::count() const
{
    return logCount;
}

// =====================================================

LogEntry LoggerManager::get(uint16_t index) const
{
    return logs[index];
}