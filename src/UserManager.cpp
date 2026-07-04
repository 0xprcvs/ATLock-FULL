#include "UserManager.h"

#include <cstring>

UserManager Users;

// =====================================================

void UserManager::begin()
{
    for (uint8_t i = 0; i < MAX_USERS; i++)
    {
        users[i].active = false;
    }
}

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

User* UserManager::findByPIN(const char* pin)
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

User* UserManager::findByRFID(const char* uid)
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

User* UserManager::currentUser()
{
    return loggedInUser;
}

// =====================================================

void UserManager::login(User* user)
{
    loggedInUser = user;
}

// =====================================================

void UserManager::logout()
{
    loggedInUser = nullptr;
}