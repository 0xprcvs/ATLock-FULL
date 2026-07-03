#include "KeypadManager.h"

#include "Pins.h"

#include <Keypad.h>

// ======================================================
// Keypad Layout
// ======================================================

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

// Convert our constexpr arrays into the format the Keypad
// library expects.
byte rowPins[ROWS] =
{
    KEYPAD_ROW_PINS[0],
    KEYPAD_ROW_PINS[1],
    KEYPAD_ROW_PINS[2],
    KEYPAD_ROW_PINS[3]
};

byte colPins[COLS] =
{
    KEYPAD_COL_PINS[0],
    KEYPAD_COL_PINS[1],
    KEYPAD_COL_PINS[2],
    KEYPAD_COL_PINS[3]
};

Keypad keypad = Keypad(
    makeKeymap(keys),
    rowPins,
    colPins,
    ROWS,
    COLS
);

// ======================================================
// Global Object
// ======================================================

KeypadManager Input;

// ======================================================

void KeypadManager::begin()
{
}

// ======================================================

void KeypadManager::update()
{
    currentKey = keypad.getKey();
}

// ======================================================

bool KeypadManager::available()
{
    return currentKey != NO_KEY;
}

// ======================================================

char KeypadManager::getKey()
{
    char key = currentKey;

    currentKey = NO_KEY;

    return key;
}

// ======================================================

bool KeypadManager::isNumber(char key)
{
    return (key >= '0' && key <= '9');
}

// ======================================================

bool KeypadManager::isConfirm(char key)
{
    return key == '#';
}

// ======================================================

bool KeypadManager::isCancel(char key)
{
    return key == '*';
}

// ======================================================

bool KeypadManager::isBack(char key)
{
    return key == 'D';
}

// ======================================================

bool KeypadManager::isAdmin(char key)
{
    return key == 'B';
}

// ======================================================

bool KeypadManager::isRestart(char key)
{
    return key == 'C';
}

// ======================================================

bool KeypadManager::isLock(char key)
{
    return key == 'A';
}