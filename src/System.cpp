#include "System.h"

#include "DisplayManager.h"

#include "Globals.h"

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

    Display.begin();

    systemInfo.systemState = SystemState::Home;

    Display.showHomeScreen();
}

// ======================================================
// Main Update Loop
// ======================================================

void SystemManager::update()
{
    Display.update();
}