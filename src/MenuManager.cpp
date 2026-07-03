#include "MenuManager.h"

#include "DisplayManager.h"

MenuManager Menu;

// =====================================================

void MenuManager::begin()
{
    activeMenu = MenuID::Home;
    selection = 0;
}

// =====================================================

void MenuManager::update()
{
}

// =====================================================

void MenuManager::open(MenuID menu)
{
    activeMenu = menu;
    selection = 0;
}

// =====================================================

void MenuManager::next()
{
    selection++;
}

// =====================================================

void MenuManager::previous()
{
    if(selection > 0)
        selection--;
}

// =====================================================

void MenuManager::select()
{
}

// =====================================================

void MenuManager::back()
{
    activeMenu = MenuID::Home;
    selection = 0;
}

// =====================================================

MenuID MenuManager::currentMenu() const
{
    return activeMenu;
}

// =====================================================

uint8_t MenuManager::currentSelection() const
{
    return selection;
}