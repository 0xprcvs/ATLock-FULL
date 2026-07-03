#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <Arduino.h>

enum class MenuID
{
    Home,

    Admin,

    Users,

    RFID,

    WiFi,

    Settings,

    Diagnostics,

    Logs,

    About
};

class MenuManager
{
public:

    void begin();

    void update();

    void open(MenuID menu);

    void next();

    void previous();

    void select();

    void back();

    MenuID currentMenu() const;

    uint8_t currentSelection() const;

private:

    MenuID activeMenu = MenuID::Home;

    uint8_t selection = 0;
};

extern MenuManager Menu;

#endif