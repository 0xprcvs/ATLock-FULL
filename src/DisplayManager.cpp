#include "DisplayManager.h"

#include "Config.h"
#include "Version.h"
#include "UIManager.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ======================================================
// OLED Display
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
// Initialize
// ======================================================

void DisplayManager::begin()
{
    Wire.begin();

    if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS))
    {
        while (true)
        {
            delay(100);
        }
    }

    oled.clearDisplay();

    UI.begin();

    showBootScreen();
}

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

    UI.drawCenteredText(
        ATLOCK_NAME,
        12,
        2
    );

    UI.drawCenteredText(
        ATLOCK_EDITION,
        34,
        1
    );

    UI.drawProgressBar(100);

    oled.display();

    delay(BOOT_SCREEN_TIME);
}

// ======================================================
// Home
// ======================================================

void DisplayManager::showHomeScreen()
{
    oled.clearDisplay();

    UI.drawHeader("ATLock");

    UI.drawCenteredText(
        "LOCKED",
        22,
        2
    );

    UI.drawCenteredText(
        "Scan Card or PIN",
        46,
        1
    );

    UI.drawFooter(
        "B Admin",
        "A Lock"
    );

    oled.display();
}

// ======================================================

void DisplayManager::showLockedScreen()
{
    showHomeScreen();
}

// ======================================================

void DisplayManager::showUnlockedScreen()
{
    oled.clearDisplay();

    UI.drawHeader("ATLock");

    UI.drawCenteredText(
        "UNLOCKED",
        22,
        2
    );

    UI.drawCenteredText(
        "Door Open",
        46,
        1
    );

    UI.drawFooter(
        "B Admin",
        "A Lock"
    );

    oled.display();
}

// ======================================================

void DisplayManager::showPINScreen(const String& pin)
{
    oled.clearDisplay();

    UI.drawHeader("Enter PIN");

    UI.drawCenteredText(
        "PIN REQUIRED",
        16,
        1
    );

    UI.drawCenteredText(
        pin,
        34,
        2
    );

    UI.drawFooter(
        "* Delete",
        "# Enter"
    );

    oled.display();
}

void DisplayManager::showRFIDScan()
{
    UI.drawMessageBox(
        "RFID",
        "Present Card"
    );
}

void DisplayManager::showAccessGranted()
{
    oled.clearDisplay();

    UI.drawHeader("ATLock");

    UI.drawCenteredText(
        "ACCESS",
        14,
        1
    );

    UI.drawCenteredText(
        "GRANTED",
        30,
        2
    );

    UI.drawFooter(
        "",
        ""
    );

    oled.display();

    delay(1000);

    showUnlockedScreen();
}

void DisplayManager::showAccessDenied()
{
    oled.clearDisplay();

    UI.drawHeader("ATLock");

    UI.drawCenteredText(
        "ACCESS",
        14,
        1
    );

    UI.drawCenteredText(
        "DENIED",
        30,
        2
    );

    UI.drawFooter(
        "",
        ""
    );

    oled.display();

    delay(1000);

    showHomeScreen();
}

void DisplayManager::showAdminLogin()
{
    UI.drawMessageBox(
        "Admin",
        "Authenticate"
    );
}

void DisplayManager::showAdminMenu()
{
    UI.drawMessageBox(
        "Admin",
        "Loading..."
    );
}

void DisplayManager::showSettings()
{
    UI.drawMessageBox(
        "Settings",
        "Loading..."
    );
}

void DisplayManager::showWiFi()
{
    UI.drawMessageBox(
        "WiFi",
        "Loading..."
    );
}

void DisplayManager::showDiagnostics()
{
    UI.drawMessageBox(
        "Diagnostics",
        "Loading..."
    );
}

void DisplayManager::showLogs()
{
    UI.drawMessageBox(
        "Logs",
        "Loading..."
    );
}

void DisplayManager::showAbout()
{
    UI.drawMessageBox(
        "About",
        FW_VERSION
    );
}

// ======================================================

void DisplayManager::showMessage(
    const String& title,
    const String& message)
{
    UI.drawMessageBox(
        title,
        message
    );
}

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