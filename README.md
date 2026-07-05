# ATLock

ATLock is a modular ESP32-based smart access control system designed for secure residential, educational, and commercial environments. It combines PIN authentication, RFID access, a web dashboard, OTA updates, and comprehensive event logging into a single embedded platform.

The project is built around a modular firmware architecture where each subsystem is isolated into its own manager, making development, maintenance, and future expansion significantly easier.

---

## Features

### Authentication

- Multi-user PIN authentication
- Variable PIN length (4–6 digits)
- RFID authentication
- Temporary PIN support
- Lockout protection after repeated failed attempts
- User session management

### Door Control

- Servo-operated locking mechanism
- Automatic relocking
- Manual lock/unlock support
- Status monitoring

### User Management

- Multiple users
- Individual PINs
- One RFID card per user
- RFID replacement support
- Duplicate RFID prevention

### Dashboard

- User management
- Temporary PIN generation
- Event logs
- Wi-Fi configuration
- Device diagnostics
- Remote lock/unlock
- OTA firmware updates

### Logging

- Authentication events
- Door events
- RFID events
- Wi-Fi events
- OTA events
- System events
- Lockout events

The dashboard's "Clear Logs" function only clears the displayed history and never deletes the permanent log file.

---

## Firmware Architecture

The firmware follows a modular architecture.

```
ATLock Firmware

├── SystemManager
├── AuthenticationManager
├── UserManager
├── DoorManager
├── DisplayManager
├── UIManager
├── KeypadManager
├── ServoManager
├── LEDManager
├── SoundManager
├── LoggerManager
├── RFIDManager
├── StorageManager
├── WiFiManager
└── APIManager
```

Each manager has a single responsibility, making the codebase easier to maintain and extend.

---

## Hardware

Current hardware includes:

- ESP32
- 4×4 Matrix Keypad
- SG90/MG90 Servo
- RC522 RFID Reader
- SSD1306 OLED Display
- Piezo Buzzer
- Status LEDs

---

## Planned Hardware

Future revisions may include:

- Fingerprint sensor
- Battery monitoring
- USB-C charging
- Higher torque locking mechanism
- Metal enclosure
- Backup battery support

---

## Dashboard

The ATLock dashboard is built using Flask and vanilla JavaScript.

Features include:

- User management
- Device settings
- Temporary PIN management
- Real-time event logging
- Diagnostics
- OTA firmware uploads
- Wi-Fi configuration

Communication between the dashboard and firmware is performed through a REST API with WebSocket support for live updates.

---

## Power

The system is designed for battery-powered operation.

Recommended power configuration:

- 12V Li-ion battery pack
- 5V buck converter
- Shared regulated 5V rail for:
  - ESP32
  - Servo
  - OLED
  - RC522
  - LEDs
  - Buzzer

Future versions will include battery monitoring and low-battery warnings.

---

## Project Status

Current development stage:

- Firmware architecture: Complete
- User management: Complete
- Authentication: Complete
- Door control: Complete
- Logging: Complete
- Dashboard architecture: Complete

Remaining work:

- RC522 hardware integration
- OLED hardware integration
- REST API implementation
- WebSocket implementation
- OTA implementation
- Persistent storage
- Dashboard synchronization
- Hardware testing
- Final optimization

---

## Repository Structure

```
ATLock/
│
├── include/
├── src/
├── static/
├── templates/
├── docs/
├── platformio.ini
└── README.md
```

---

## Roadmap

### Version 0.3

- Modular firmware architecture
- User management
- Authentication system
- Dashboard framework

### Version 0.4

- RFID integration
- Wi-Fi connectivity
- REST API
- Dashboard synchronization

### Version 0.5

- OTA updates
- Persistent storage
- Diagnostics
- Performance improvements

### Version 1.0

- Complete hardware integration
- Stable firmware
- Full dashboard support
- Production-ready release

---

## License

This project is currently under active development.

All rights reserved unless otherwise specified.

---

ATLock is developed as a modular embedded access control platform focused on reliability, maintainability, and future expansion.
