#ifndef RFIDMANAGER_H
#define RFIDMANAGER_H

#include <Arduino.h>

class RFIDManager
{
public:

    void begin();

    void update();

    bool available();

    String readUID();

private:

    bool cardAvailable = false;

    String uid = "";
};

extern RFIDManager RFID;

#endif