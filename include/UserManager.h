#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <Arduino.h>

constexpr uint8_t MAX_USERS = 20;

struct User
{
    char username[21];
    char pin[7];       // 4-6 digits
    char rfid[20];     // Empty = no card registered
    bool active;
};

class UserManager
{
public:

    void begin();

    bool addUser(
        const char* username,
        const char* pin
    );

    User* findByPIN(
        const char* pin
    );

    User* findByRFID(
        const char* uid
    );

    User* currentUser();

    void login(User* user);

    void logout();

private:

    User users[MAX_USERS];

    User* loggedInUser = nullptr;
};

extern UserManager Users;

#endif