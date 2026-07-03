#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <Arduino.h>
#include "Globals.h"

class StateManager
{
public:

    void begin();

    void update();

    void setState(SystemState newState);

    SystemState getState() const;

    bool is(SystemState state) const;

private:

    SystemState currentState = SystemState::Boot;

};

extern StateManager State;

#endif