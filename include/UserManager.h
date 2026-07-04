#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <Arduino.h>
#include "Config.h"

// =====================================================
// User Structure
// =====================================================

struct User
{
    char username[21];
    char pin[7];          // 4-6 digit PIN
    char rfid[20];        // Empty if no RFID registered
    bool active;
};

// =====================================================
// User Manager
// =====================================================

class UserManager
{
public:

    // Initialization
    void begin();

    // User Management
    bool addUser(
        const char* username,
        const char* pin
    );

    // Lookup
    User* findByPIN(
        const char* pin
    );

    User* findByRFID(
        const char* uid
    );

    // Login Session
    User* currentUser();

    void login(
        User* user
    );

    void logout();

    // RFID Management
    bool registerCurrentUserRFID(
        const char* uid
    );

    bool isRFIDRegistered(
        const char* uid
    );

    void clearCurrentUserRFID();

    // Storage Helpers
    uint8_t userCount() const;

    User* getUser(
        uint8_t index
    );

private:

    User users[MAX_USERS];

    User* loggedInUser = nullptr;
};

// =====================================================

extern UserManager Users;

#endif