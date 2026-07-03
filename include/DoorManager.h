#ifndef DOORMANAGER_H
#define DOORMANAGER_H

#include <Arduino.h>

class DoorManager
{
public:

    void begin();

    void update();

    void lock();

    void unlock();

    bool isLocked() const;

private:

    bool locked = true;

    unsigned long unlockTime = 0;
};

extern DoorManager Door;

#endif