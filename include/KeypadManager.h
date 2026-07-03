#ifndef KEYPADMANAGER_H
#define KEYPADMANAGER_H

#include <Arduino.h>

class KeypadManager
{
public:

    void begin();

    void update();

    bool available();

    char getKey();

    bool isNumber(char key);

    bool isConfirm(char key);

    bool isCancel(char key);

    bool isBack(char key);

    bool isAdmin(char key);

    bool isRestart(char key);

    bool isLock(char key);

private:

    char currentKey = '\0';

};

extern KeypadManager Input;

#endif