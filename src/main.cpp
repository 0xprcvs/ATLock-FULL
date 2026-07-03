#include <Arduino.h>

#include "System.h"

void setup()
{
    System.begin();
}

void loop()
{
    System.update();
}