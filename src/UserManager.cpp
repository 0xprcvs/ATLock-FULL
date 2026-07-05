#include "UserManager.h"

#include <cstring>

UserManager Users;

// =====================================================
// Initialize
// =====================================================

void UserManager::begin()
{
    for (uint8_t i = 0; i < MAX_USERS; i++)
    {
        users[i].active = false;

        users[i].username[0] = '\0';
        users[i].pin[0] = '\0';
        users[i].rfid[0] = '\0';
    }

    loggedInUser = nullptr;
}

// =====================================================
// Add User
// =====================================================

bool UserManager::addUser(
    const char* username,
    const char* pin)
{
    for (uint8_t i = 0; i < MAX_USERS; i++)
    {
        if (!users[i].active)
        {
            strcpy(users[i].username, username);
            strcpy(users[i].pin, pin);

            users[i].rfid[0] = '\0';

            users[i].active = true;

            return true;
        }
    }

    return false;
}

// =====================================================
// Find User By PIN
// =====================================================

User* UserManager::findByPIN(
    const char* pin)
{
    for (uint8_t i = 0; i < MAX_USERS; i++)
    {
        if (users[i].active &&
            strcmp(users[i].pin, pin) == 0)
        {
            return &users[i];
        }
    }

    return nullptr;
}

// =====================================================
// Find User By RFID
// =====================================================

User* UserManager::findByRFID(
    const char* uid)
{
    for (uint8_t i = 0; i < MAX_USERS; i++)
    {
        if (users[i].active &&
            strcmp(users[i].rfid, uid) == 0)
        {
            return &users[i];
        }
    }

    return nullptr;
}

// =====================================================
// Current User
// =====================================================

User* UserManager::currentUser()
{
    return loggedInUser;
}

// =====================================================
// Login
// =====================================================

void UserManager::login(
    User* user)
{
    loggedInUser = user;
}

// =====================================================
// Logout
// =====================================================

void UserManager::logout()
{
    loggedInUser = nullptr;
}

// =====================================================
// RFID Registered?
// =====================================================

bool UserManager::isRFIDRegistered(
    const char* uid)
{
    return findByRFID(uid) != nullptr;
}

// =====================================================
// Register Current User RFID
// =====================================================

bool UserManager::registerCurrentUserRFID(
    const char* uid)
{
    if (loggedInUser == nullptr)
        return false;

    User* existing = findByRFID(uid);

    if (existing != nullptr &&
        existing != loggedInUser)
    {
        return false;
    }

    strcpy(
        loggedInUser->rfid,
        uid
    );

    return true;
}

// =====================================================
// Clear Current User RFID
// =====================================================

void UserManager::clearCurrentUserRFID()
{
    if (loggedInUser == nullptr)
        return;

    loggedInUser->rfid[0] = '\0';
}

// =====================================================
// User Count
// =====================================================

uint8_t UserManager::userCount() const
{
    uint8_t count = 0;

    for (uint8_t i = 0; i < MAX_USERS; i++)
    {
        if (users[i].active)
        {
            count++;
        }
    }

    return count;
}

// =====================================================
// Get User
// =====================================================

User* UserManager::getUser(
    uint8_t index)
{
    if (index >= MAX_USERS)
        return nullptr;

    return &users[index];
}

// =====================================================
// Set User RFID
// =====================================================

bool UserManager::setUserRFID(
    const char* username,
    const char* uid)
{
    for(uint8_t i = 0; i < MAX_USERS; i++)
    {
        if(users[i].active &&
           strcmp(users[i].username, username) == 0)
        {
            strcpy(users[i].rfid, uid);
            return true;
        }
    }

    return false;
}