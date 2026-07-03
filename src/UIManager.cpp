#include "UIManager.h"
#include "Icons.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 oled;

UIManager UI;

void UIManager::begin()
{
}

void UIManager::drawHeader(const String& title)
{
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(1);

    oled.drawBitmap(
        0,
        0,
        ICON_LOCK,
        8,
        8,
        SSD1306_WHITE
    );

    oled.setCursor(12,0);
    oled.print(title);

    oled.drawBitmap(
        118,
        0,
        ICON_WIFI,
        8,
        8,
        SSD1306_WHITE
    );

    oled.drawLine(0,10,127,10,SSD1306_WHITE);
}

void UIManager::drawFooter(
    const String& leftText,
    const String& rightText)
{
    oled.drawLine(0,54,127,54,SSD1306_WHITE);

    oled.setCursor(0,57);
    oled.print(leftText);

    int16_t x1,y1;
    uint16_t w,h;

    oled.getTextBounds(
        rightText,
        0,
        0,
        &x1,
        &y1,
        &w,
        &h
    );

    oled.setCursor(127-w,57);
    oled.print(rightText);
}

void UIManager::drawDivider(uint8_t y)
{
    oled.drawLine(
        0,
        y,
        127,
        y,
        SSD1306_WHITE
    );
}

void UIManager::drawCenteredText(
    const String& text,
    uint8_t y,
    uint8_t size)
{
    oled.setTextSize(size);

    int16_t x1,y1;
    uint16_t w,h;

    oled.getTextBounds(
        text,
        0,
        0,
        &x1,
        &y1,
        &w,
        &h
    );

    oled.setCursor(
        (128-w)/2,
        y
    );

    oled.print(text);

    oled.setTextSize(1);
}

void UIManager::drawMessageBox(
    const String& title,
    const String& message)
{
    oled.clearDisplay();

    drawHeader(title);

    oled.drawRoundRect(
        8,
        18,
        112,
        28,
        4,
        SSD1306_WHITE
    );

    drawCenteredText(
        message,
        28,
        1
    );

    oled.display();
}

void UIManager::drawProgressBar(uint8_t percent)
{
    percent = constrain(percent,0,100);

    oled.drawRoundRect(
        10,
        44,
        108,
        12,
        3,
        SSD1306_WHITE
    );

    uint8_t width = map(
        percent,
        0,
        100,
        0,
        104
    );

    oled.fillRoundRect(
        12,
        46,
        width,
        8,
        2,
        SSD1306_WHITE
    );
}

void UIManager::drawSelection(
    uint8_t x,
    uint8_t y)
{
    oled.fillCircle(
        x,
        y,
        2,
        SSD1306_WHITE
    );
}

void UIManager::fadeIn()
{
}

void UIManager::fadeOut()
{
}

void UIManager::slideLeft()
{
}

void UIManager::slideRight()
{
}