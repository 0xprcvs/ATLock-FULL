#include "System.h"
#include "LoggerManager.h"
#include "DisplayManager.h"
#include "KeypadManager.h"
#include "AuthenticationManager.h"
#include "DoorManager.h"
#include "Globals.h"
#include "PINManager.h"

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

    Input.begin();

    PIN.begin();

    Auth.begin();

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
                PIN.backspace();

                Display.showPINScreen(
                    PIN.masked()
                );
            }

            else if (Input.isConfirm(key))
            {
                if (PIN.complete())
                {
                    Auth.authenticatePIN(
                        PIN.value()
                    );
                }

                PIN.clear();

                enteringPIN = false;

                Display.showHomeScreen();
            }
        }
    }

    Display.update();
}