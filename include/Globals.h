#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

// ======================================================
// ATLock FULL VERSION
// Global Enums & Structures
// ======================================================

// -------------------------
// Door State
// -------------------------
enum class DoorState
{
    Locked,
    Unlocked,
    Locking,
    Unlocking
};

// -------------------------
// System State
// -------------------------
enum class SystemState
{
    Boot,

    Home,

    EnterPIN,

    ScanRFID,

    Granted,

    Denied,

    AdminLogin,

    AdminMenu,

    Settings,

    WiFi,

    Diagnostics,

    Logs,

    Restarting,

    OTA,

    Sleeping
};

// -------------------------
// User Type
// -------------------------
enum class UserType
{
    Admin,

    User,

    Guest
};

// -------------------------
// Authentication Method
// -------------------------
enum class AuthMethod
{
    None,

    PIN,

    RFID,

    Dashboard
};

// -------------------------
// Authentication Result
// -------------------------
enum class AuthResult
{
    Success,

    Failed,

    LockedOut
};

// -------------------------
// RGB Status (future use)
// -------------------------
enum class LEDStatus
{
    Off,

    Green,

    Red,

    Yellow
};

// -------------------------
// Sound Types
// -------------------------
enum class SoundType
{
    None,

    Startup,

    Lock,

    Unlock,

    Granted,

    Denied,

    Warning,

    Error,

    Menu
};

// -------------------------
// System Information
// -------------------------
struct SystemInfo
{
    DoorState doorState = DoorState::Locked;

    SystemState systemState = SystemState::Boot;

    bool wifiConnected = false;

    bool displaySleeping = false;

    bool adminLoggedIn = false;
};

// Global system information
extern SystemInfo systemInfo;

#endif