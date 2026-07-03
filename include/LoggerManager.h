#ifndef LOGGERMANAGER_H
#define LOGGERMANAGER_H

#include <Arduino.h>

enum class LogLevel
{
    Info,
    Warning,
    Error,
    Debug
};

struct LogEntry
{
    unsigned long timestamp;
    LogLevel level;
    String message;
};

class LoggerManager
{
public:

    void begin();

    void update();

    void clear();

    void log(
        LogLevel level,
        const String& message
    );

    uint16_t count() const;

    LogEntry get(uint16_t index) const;

private:

    static const uint16_t MAX_LOGS = 100;

    LogEntry logs[MAX_LOGS];

    uint16_t logCount = 0;
};

extern LoggerManager Logger;

#endif