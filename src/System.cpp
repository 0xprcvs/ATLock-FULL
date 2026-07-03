#include "System.h"

#include "DisplayManager.h"
#include "KeypadManager.h"
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

// ======================================================
// Initialize System
// ======================================================

void SystemManager::begin()
{
    Serial.begin(115200);

    PIN.begin();
    
    Display.begin();

    Input.begin();

    systemInfo.systemState = SystemState::Home;

    Display.showHomeScreen();
}

// ======================================================
// Main Update Loop
// ======================================================

void SystemManager::update()
{
    if (Input.available())
{
    char key = Input.getKey();

    // Number pressed
    if (Input.isNumber(key))
    {
        PIN.addDigit(key);

        Display.showPINScreen(
            PIN.masked()
        );
    }

    // Delete
    else if (Input.isCancel(key))
    {
        PIN.backspace();

        Display.showPINScreen(
            PIN.masked()
        );
    }

    // Confirm
    else if (Input.isConfirm(key))
    {
        if (PIN.complete())
        {
            Serial.print("Entered PIN: ");
            Serial.println(PIN.value());

            // Authentication comes next
        }
    }
}
    Display.update();
}