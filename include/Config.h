#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ======================================================
// ATLock FULL VERSION
// System Configuration
// ======================================================

// -------------------------
// OLED
// -------------------------
constexpr uint8_t OLED_I2C_ADDRESS = 0x3C;
constexpr uint16_t OLED_WIDTH = 128;
constexpr uint16_t OLED_HEIGHT = 64;

// -------------------------
// Servo Configuration
// -------------------------
constexpr uint8_t SERVO_LOCK_POSITION = 0;
constexpr uint8_t SERVO_UNLOCK_POSITION = 90;

constexpr uint16_t SERVO_MOVE_DELAY = 15;

// -------------------------
// Door
// -------------------------
constexpr uint32_t AUTO_LOCK_TIME = 5000;      // milliseconds

// -------------------------
// Display
// -------------------------
constexpr uint32_t BOOT_SCREEN_TIME = 2000;
constexpr uint32_t SPLASH_SCREEN_TIME = 1500;

// -------------------------
// Sleep Mode
// -------------------------
constexpr uint32_t DISPLAY_SLEEP_TIMEOUT = 10000;

// -------------------------
// Authentication
// -------------------------
constexpr uint8_t PIN_LENGTH = 6;

constexpr uint8_t MAX_PIN_ATTEMPTS = 5;

constexpr uint32_t LOCKOUT_TIME = 30000;

// -------------------------
// RFID
// -------------------------
constexpr uint8_t MAX_USERS = 50;
constexpr uint8_t MAX_RFID_CARDS = 100;

// -------------------------
// Buzzer
// -------------------------
constexpr uint16_t BUZZER_FREQUENCY = 2500;

constexpr uint16_t BUZZER_SHORT_BEEP = 100;
constexpr uint16_t BUZZER_LONG_BEEP = 300;

// -------------------------
// Wi-Fi
// -------------------------
constexpr uint32_t WIFI_CONNECT_TIMEOUT = 15000;

// -------------------------
// EEPROM / Preferences
// -------------------------
constexpr const char* PREF_NAMESPACE = "ATLock";

// -------------------------
// Firmware
// -------------------------
constexpr bool SERIAL_DEBUG = true;

#endif