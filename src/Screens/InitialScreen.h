#ifndef INITIALSCREEN_H
#define INITIALSCREEN_H

#include "StaticScreen.h"
#include <U8g2lib.h>

#include "Bitmaps/Logo.h"

class InitialScreen : public StaticScreen
{

public:
    InitialScreen() {}

    void show(U8G2 *display) override
    {
        display->clearBuffer();

        display->drawXBMP(56, 24, 16, 16, itc_logo);

        display->setFont(u8g2_font_4x6_tr);
        const char *text = "sharing is caring.";
        uint8_t textWidth = display->getStrWidth(text);
        uint8_t textX = (128 - textWidth) / 2;
        display->drawStr(textX, 55, text);

        display->sendBuffer();
    }
    // Override the getType method to return STATIC_SCREEN
    ScreenType getType() const override
    {
        return STATIC_SCREEN;
    }
};

#endif