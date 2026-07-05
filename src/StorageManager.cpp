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
    preferences.clear();

    preferences.putUInt("count", MAX_USERS);

    char key[8];
    char value[64];

    for(uint8_t i = 0; i < MAX_USERS; i++)
    {
        User* user = Users.getUser(i);

        if(user == nullptr || !user->active)
            continue;

        sprintf(key, "u%d", i);

        sprintf(
            value,
            "%s|%s|%s",
            user->username,
            user->pin,
            user->rfid
        );

        preferences.putString(key, value);
    }
}

// =====================================================

void StorageManager::loadUsers()
{
    char key[8];

    for(uint8_t i = 0; i < MAX_USERS; i++)
    {
        sprintf(key, "u%d", i);

        String value = preferences.getString(key, "");

        if(value == "")
            continue;

        int p1 = value.indexOf('|');
        int p2 = value.lastIndexOf('|');

        if(p1 == -1 || p2 == -1)
            continue;

        String username = value.substring(0, p1);
        String pin = value.substring(p1 + 1, p2);
        String rfid = value.substring(p2 + 1);

        Users.addUser(
            username.c_str(),
            pin.c_str()
        );

        if(rfid.length() > 0)
        {
            Users.setUserRFID(
                username.c_str(),
                rfid.c_str()
            );
        }
    }
}