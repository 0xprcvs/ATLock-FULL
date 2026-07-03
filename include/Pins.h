#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

// ======================================================
// ATLock FULL VERSION
// ESP32 Pin Configuration
// ======================================================

// -------------------------
// OLED Display (SSD1306)
// -------------------------
constexpr uint8_t OLED_SDA_PIN = 21;
constexpr uint8_t OLED_SCL_PIN = 22;

// -------------------------
// RFID (MFRC522)
// -------------------------
constexpr uint8_t RFID_SS_PIN   = 5;
constexpr uint8_t RFID_RST_PIN  = 4;
constexpr uint8_t RFID_SCK_PIN  = 18;
constexpr uint8_t RFID_MOSI_PIN = 23;
constexpr uint8_t RFID_MISO_PIN = 19;
constexpr uint8_t RFID_IRQ_PIN  = 34;

// -------------------------
// Servo
// -------------------------
constexpr uint8_t SERVO_PIN = 13;

// -------------------------
// LEDs
// -------------------------
constexpr uint8_t GREEN_LED_PIN = 17;
constexpr uint8_t RED_LED_PIN   = 2;

// -------------------------
// Passive Buzzer
// -------------------------
constexpr uint8_t BUZZER_PIN = 0;

// -------------------------
// Inside Unlock Button
// -------------------------
constexpr uint8_t INSIDE_BUTTON_PIN = 16;

// -------------------------
// 4x4 Matrix Keypad
// -------------------------
constexpr uint8_t KEYPAD_ROW_PINS[4] = {
    32,
    33,
    25,
    26
};

constexpr uint8_t KEYPAD_COL_PINS[4] = {
    27,
    14,
    12,
    15
};

// -------------------------
// I2C Configuration
// -------------------------
constexpr uint8_t I2C_SDA_PIN = OLED_SDA_PIN;
constexpr uint8_t I2C_SCL_PIN = OLED_SCL_PIN;

// -------------------------
// SPI Configuration
// -------------------------
constexpr uint8_t SPI_SCK_PIN  = RFID_SCK_PIN;
constexpr uint8_t SPI_MISO_PIN = RFID_MISO_PIN;
constexpr uint8_t SPI_MOSI_PIN = RFID_MOSI_PIN;

#endif