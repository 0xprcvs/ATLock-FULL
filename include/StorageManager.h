#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <Arduino.h>
#include <Preferences.h>

class StorageManager
{
public:

    void begin();

    void loadUsers();

    void saveUsers();

private:

    Preferences preferences;
};

extern StorageManager Storage;

#endif