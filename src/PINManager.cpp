#include "PINManager.h"
#include "Config.h"
PINManager PIN;

// =====================================================

void PINManager::begin()
{
    clear();
}

// =====================================================

void PINManager::update()
{
}

// =====================================================

void PINManager::clear()
{
    pin = "";
}

// =====================================================

void PINManager::addDigit(char digit)
{
    if (pin.length() >= MAX_PIN_LENGTH)
        return;

    if(digit < '0' || digit > '9')
        return;

    pin += digit;
}

// =====================================================

void PINManager::backspace()
{
    if(pin.length() == 0)
        return;

    pin.remove(pin.length() - 1);
}

// =====================================================

bool PINManager::complete() const
    {
        return pin.length() > 0;
    }
// =====================================================

String PINManager::value() const
{
    return pin;
}

String PINManager::masked() const
{
    String stars = "";

    for(size_t i = 0; i < pin.length(); i++)
        stars += "*";

    return stars;
}