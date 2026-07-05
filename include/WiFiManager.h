#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <Arduino.h>
#include <WiFi.h>

class WiFiManager
{
public:

    void begin();

    void update();

    bool connect(
        const char* ssid,
        const char* password
    );

    void disconnect();

    bool connected() const;

    String ssid() const;

    String ipAddress() const;

    int signalStrength() const;

    void beginOTA();

    void updateOTA();

    bool otaRunning() const;

private:

    bool wifiConnected = false;

    bool updating = false;
};

extern WiFiManager WiFiMgr;


#endif