#include "System.h"
#include "LoggerManager.h"
#include "DisplayManager.h"
#include "KeypadManager.h"
#include "AuthenticationManager.h"
#include "DoorManager.h"
#include "Globals.h"
#include "PINManager.h"
#include "APIManager.h"
#include "PreferencesManager.h"
#include "TempPINManager.h"
#include "StorageManager.h"
#include "WiFiManager.h"
#include "UserManager.h"
#include "RFIDManager.h"
#include <Arduino.h>

// ======================================================
// Global System
// ======================================================

SystemManager System;

// ======================================================
// Global Variables
// ======================================================

SystemInfo systemInfo;
bool enteringPIN = false;

// ======================================================
// Initialize System
// ======================================================

void SystemManager::begin()
{
    Serial.begin(115200);

    Display.begin();

    WiFiMgr.begin();

    API.begin();

    Users.begin();

    Storage.begin();
    Storage.loadUsers();

    PreferencesMgr.begin();
    
    Input.begin();

    PIN.begin();

    TempPINs.begin();

    Auth.begin();
    RFID.begin();

    Door.begin();

    systemInfo.systemState = SystemState::Home;

    Display.showHomeScreen();

    Logger.begin();

Logger.log(
    LogLevel::Info,
    "ATLock Started"
);
}

// ======================================================
// Main Update Loop
// ======================================================

void SystemManager::update()
{
    Input.update();

    Door.update();

    Auth.update();

    API.update();

    WiFiMgr.update();

    RFID.update();

if (RFID.available())
{
    String uid = RFID.readUID();

    User* user = Users.findByRFID(uid.c_str());

    if (user != nullptr)
    {
        Users.login(user);

        Door.unlock();
    }
}

    TempPINs.update();

    Logger.update();

    if (Input.available())
    {
        char key = Input.getKey();

        // -------------------------
        // HOME MODE
        // -------------------------

        if (!enteringPIN)
        {
            if (Input.isConfirm(key))
            {
                enteringPIN = true;

                PIN.clear();

                Display.showPINScreen(
                    PIN.masked()
                );
            }
        }

        // -------------------------
        // PIN ENTRY MODE
        // -------------------------

        else
        {
            if (Input.isNumber(key))
            {
                PIN.addDigit(key);

                Display.showPINScreen(
                    PIN.masked()
                );
            }

          else if (Input.isCancel(key))
{
    if (PIN.value().length() > 0)
    {
        PIN.backspace();

        Display.showPINScreen(
            PIN.masked()
        );
    }
    else
    {
        PIN.clear();

        enteringPIN = false;

        Display.showHomeScreen();
    }
}

          else if (Input.isConfirm(key))
{
    if (!PIN.complete())
        return;

    bool success = Auth.authenticatePIN(
        PIN.value()
    );

    PIN.clear();

    if (success)
    {
        enteringPIN = false;

        Display.showAccessGranted();
    }
    else
    {
        Display.showAccessDenied();

        delay(1200);

        Display.showPINScreen(
            PIN.masked()
        );
    }
}
        }
    }

    Display.update();
}