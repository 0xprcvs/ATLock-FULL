#ifndef PINMANAGER_H
#define PINMANAGER_H

#include <Arduino.h>

class PINManager
{
public:

    void begin();

    void update();

    void clear();

    void addDigit(char digit);

    void backspace();

    bool complete() const;

    String value() const;

    String masked() const;

private:

    String pin = "";

    static constexpr uint8_t MAX_PIN_LENGTH = 4;
};

extern PINManager PIN;

#endif