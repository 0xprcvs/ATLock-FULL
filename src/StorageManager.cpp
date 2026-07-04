#include "StorageManager.h"
#include "UserManager.h"

StorageManager Storage;

// =====================================================

void StorageManager::begin()
{
    preferences.begin("atlock", false);
}

// =====================================================

void StorageManager::saveUsers()
{
    preferences.putUInt(
        "count",
        MAX_USERS
    );

    char key[10];
    char data[64];

    for(uint8_t i=0;i<MAX_USERS;i++)
    {
        User* user = Users.getUser(i);

        sprintf(
            key,
            "u%d",
            i
        );

        if(user->active)
        {
            sprintf(
                data,
                "%s|%s|%s",
                user->username,
                user->pin,
                user->rfid
            );

            preferences.putString(
                key,
                data
            );
        }
        else
        {
            preferences.remove(key);
        }
    }
}

// =====================================================

void StorageManager::loadUsers()
{
    // Coming next
}