#ifndef VERSION_H
#define VERSION_H

// ======================================================
// ATLock FULL VERSION
// Firmware Version Information
// ======================================================

// Project Information
constexpr const char* ATLOCK_NAME        = "ATLock";
constexpr const char* ATLOCK_EDITION     = "FULL VERSION";

// Firmware Version
constexpr const char* FW_VERSION         = "0.1.0";
constexpr const char* FW_STAGE           = "Alpha";

// Build Information
constexpr const char* FW_BUILD_DATE      = __DATE__;
constexpr const char* FW_BUILD_TIME      = __TIME__;

// Developer Information
constexpr const char* FW_AUTHOR          = "Precious";
constexpr const char* FW_COMPANY         = "ATL Lab";

// Device Information
constexpr const char* DEVICE_MODEL       = "ATLock-FULL";
constexpr const char* DEVICE_PLATFORM    = "ESP32";

// Display Information
constexpr const char* DISPLAY_TYPE       = "SSD1306 OLED";
constexpr const char* DISPLAY_RESOLUTION = "128x64";

// Hardware Version
constexpr const char* HARDWARE_REVISION  = "1.0";

// Copyright
constexpr const char* COPYRIGHT_NOTICE =
    "Copyright (c) 2026 ATL Lab. All rights reserved.";

#endif