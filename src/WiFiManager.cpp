#include "WiFiManager.h"
#include <ArduinoOTA.h>
WiFiManager WiFiMgr;

// =====================================================

void WiFiManager::begin()
{
}

// =====================================================

void WiFiManager::update()
{
    wifiConnected = WiFi.status() == WL_CONNECTED;
    if (wifiConnected)
{
    updateOTA();
}
}

// =====================================================

bool WiFiManager::connect(
    const char* ssid,
    const char* password)
{
    WiFi.begin(ssid, password);

    unsigned long start = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - start > 10000)
        {
            wifiConnected = false;
            return false;
        }

        delay(250);
    }

    wifiConnected = true;
    beginOTA();
    return true;
}

// =====================================================

void WiFiManager::disconnect()
{
    WiFi.disconnect(true);

    wifiConnected = false;
}

// =====================================================

bool WiFiManager::connected() const
{
    return wifiConnected;
}

// =====================================================

String WiFiManager::ssid() const
{
    return WiFi.SSID();
}

// =====================================================

String WiFiManager::ipAddress() const
{
    return WiFi.localIP().toString();
}

// =====================================================

int WiFiManager::signalStrength() const
{
    return WiFi.RSSI();
}

// =====================================================

void WiFiManager::beginOTA()
{
    ArduinoOTA.setHostname("ATLock");

    ArduinoOTA.begin();
}

// =====================================================

void WiFiManager::updateOTA()
{
    ArduinoOTA.handle();
}

// =====================================================

bool WiFiManager::otaRunning() const
{
    return updating;
}