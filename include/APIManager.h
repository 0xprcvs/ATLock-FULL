#ifndef APIMANAGER_H
#define APIMANAGER_H

#include <Arduino.h>

class APIManager
{
public:

    void begin();

    void update();

    void sendStatus();

    void sendLogs();

    void sendUsers();

    void sendSettings();

    void sendWiFi();

    void sendDiagnostics();

    void unlockDoor();

    void lockDoor();

    void changePIN(
        const char* username,
        const char* pin
    );

    void addRFID(
        const char* username,
        const char* uid
    );

};

extern APIManager API;

#endif