#include "DisplayManager.h"

#include "Version.h"
#include "Config.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ======================================================
// OLED Object
// ======================================================

Adafruit_SSD1306 oled(
    OLED_WIDTH,
    OLED_HEIGHT,
    &Wire,
    -1
);

// ======================================================
// Global Display Manager
// ======================================================

DisplayManager Display;

// ======================================================
// Initialize Display
// ======================================================

void DisplayManager::begin()
{
    Wire.begin();

    if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS))
    {
        Serial.println("OLED initialization failed.");

        while (true)
        {
            delay(100);
        }
    }

    initialized = true;

    clear();

    showBootScreen();
}

// ======================================================
// Update
// ======================================================

void DisplayManager::update()
{
}

// ======================================================
// Boot Screen
// ======================================================

void DisplayManager::showBootScreen()
{
    oled.clearDisplay();

    oled.setTextColor(SSD1306_WHITE);

    oled.setTextSize(2);
    oled.setCursor(18, 12);
    oled.println("ATLock");

    oled.setTextSize(1);
    oled.setCursor(26, 36);
    oled.println(ATLOCK_EDITION);

    oled.setCursor(34, 52);
    oled.print("v");
    oled.print(FW_VERSION);

    oled.display();

    delay(BOOT_SCREEN_TIME);
}

// ======================================================
// Home Screen
// ======================================================

void DisplayManager::showHomeScreen()
{
    oled.clearDisplay();

    oled.setTextSize(1);
    oled.setCursor(0, 0);
    oled.println("ATLock");

    oled.drawLine(0, 10, 127, 10, SSD1306_WHITE);

    oled.setCursor(20, 24);
    oled.println("System Ready");

    oled.setCursor(8, 48);
    oled.println("Waiting for Input");

    oled.display();
}

// ======================================================
// Locked Screen
// ======================================================

void DisplayManager::showLockedScreen()
{
    showHomeScreen();
}

// ======================================================
// Unlocked Screen
// ======================================================

void DisplayManager::showUnlockedScreen()
{
    oled.clearDisplay();

    oled.setTextSize(2);
    oled.setCursor(12, 20);
    oled.println("UNLOCKED");

    oled.display();
}

// ======================================================
// PIN Screen
// ======================================================

void DisplayManager::showPINScreen(const String &pin)
{
}

// ======================================================
// RFID Screen
// ======================================================

void DisplayManager::showRFIDScan()
{
}

// ======================================================
// Granted
// ======================================================

void DisplayManager::showAccessGranted()
{
}

// ======================================================
// Denied
// ======================================================

void DisplayManager::showAccessDenied()
{
}

// ======================================================
// Admin
// ======================================================

void DisplayManager::showAdminLogin()
{
}

void DisplayManager::showAdminMenu()
{
}

// ======================================================
// Settings
// ======================================================

void DisplayManager::showSettings()
{
}

void DisplayManager::showWiFi()
{
}

void DisplayManager::showDiagnostics()
{
}

void DisplayManager::showLogs()
{
}

void DisplayManager::showAbout()
{
}

// ======================================================
// Message Box
// ======================================================

void DisplayManager::showMessage(
    const String &title,
    const String &message)
{
    oled.clearDisplay();

    oled.setTextSize(1);

    oled.setCursor(0, 0);
    oled.println(title);

    oled.drawLine(0, 10, 127, 10, SSD1306_WHITE);

    oled.setCursor(0, 24);
    oled.println(message);

    oled.display();
}

// ======================================================
// Utility
// ======================================================

void DisplayManager::clear()
{
    oled.clearDisplay();
    oled.display();
}

void DisplayManager::sleep()
{
    oled.ssd1306_command(SSD1306_DISPLAYOFF);
}

void DisplayManager::wake()
{
    oled.ssd1306_command(SSD1306_DISPLAYON);
}