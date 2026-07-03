#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <Arduino.h>

class DisplayManager
{
public:

    // Initialization
    void begin();

    // Update Display
    void update();

    // Main Screens
    void showBootScreen();
    void showHomeScreen();
    void showLockedScreen();
    void showUnlockedScreen();

    // Authentication
    void showPINScreen(const String &pin);
    void showRFIDScan();
    void showAccessGranted();
    void showAccessDenied();

    // Administrator
    void showAdminLogin();
    void showAdminMenu();

    // Settings
    void showSettings();
    void showWiFi();
    void showDiagnostics();
    void showLogs();
    void showAbout();

    // Utility
    void showMessage(
        const String &title,
        const String &message
    );

    void clear();

    void sleep();

    void wake();

private:

    bool initialized = false;
};

// Global Display Manager
extern DisplayManager Display;

#endif