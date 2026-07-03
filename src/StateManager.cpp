#include "StateManager.h"

#include "DisplayManager.h"

StateManager State;

void StateManager::begin()
{
    currentState = SystemState::Boot;
}

void StateManager::update()
{
}

void StateManager::setState(SystemState newState)
{
    currentState = newState;

    switch(currentState)
    {
        case SystemState::Boot:

            Display.showBootScreen();

            break;

        case SystemState::Home:

            Display.showHomeScreen();

            break;

        case SystemState::Granted:

            Display.showAccessGranted();

            break;

        case SystemState::Denied:

            Display.showAccessDenied();

            break;

        case SystemState::AdminLogin:

            Display.showAdminLogin();

            break;

        case SystemState::AdminMenu:

            Display.showAdminMenu();

            break;

        case SystemState::Settings:

            Display.showSettings();

            break;

        case SystemState::WiFi:

            Display.showWiFi();

            break;

        case SystemState::Diagnostics:

            Display.showDiagnostics();

            break;

        case SystemState::Logs:

            Display.showLogs();

            break;

        default:

            break;
    }
}

SystemState StateManager::getState() const
{
    return currentState;
}

bool StateManager::is(SystemState state) const
{
    return currentState == state;
}