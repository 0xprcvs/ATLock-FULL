#ifndef SERVOMANAGER_H
#define SERVOMANAGER_H

#include <Arduino.h>

class ServoManager
{
public:

    void begin();

    void update();

    void lock();

    void unlock();

    bool isLocked() const;

    uint8_t currentAngle() const;

private:

    bool locked = true;

    uint8_t angle = 0;
};

extern ServoManager ServoMgr;

#endif