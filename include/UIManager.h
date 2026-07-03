#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <Arduino.h>

class UIManager
{
public:

    // Initialize
    void begin();

    // Common UI Elements
    void drawHeader(
        const String& title
    );

    void drawFooter(
        const String& leftText,
        const String& rightText
    );

    void drawDivider(
        uint8_t y
    );

    void drawCenteredText(
        const String& text,
        uint8_t y,
        uint8_t size = 1
    );

    void drawMessageBox(
        const String& title,
        const String& message
    );

    void drawProgressBar(
        uint8_t percent
    );

    void drawSelection(
        uint8_t x,
        uint8_t y
    );

    // Future Animation Hooks
    void fadeIn();

    void fadeOut();

    void slideLeft();

    void slideRight();

};

extern UIManager UI;

#endif