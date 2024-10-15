#ifndef ITCSCREEN_H
#define ITCSCREEN_H

#include "StaticScreen.h"
#include <U8g2lib.h>

#include "Bitmaps/StaticScreenIcons.h"

class ITCScreen : public StaticScreen
{

public:
    ITCScreen() {}

    void show(U8G2 *display) override
    {
        display->clearBuffer();

        // Drawing the header rectangle
        display->drawXBMP(1, 1, 126, 12, header);

        // Centering and drawing the title "ITC"
        display->setFont(u8g2_font_ncenB08_tr);                                                 // Choose a suitable font
        display->drawStr((128 - display->getStrWidth("IT Community")) / 2, 11, "IT Community"); // Draws at y = 9 for header

        // Writing the description text below the header
        display->setFont(u8g2_font_5x7_tr);
        display->drawStr(1, 21, "ITC, a scientific club");
        display->drawStr(1, 31, "founded in 2016 to share");
        display->drawStr(1, 41, "knowledge within members");
        display->drawStr(1, 51, "in many different fields.");

        display->drawXBMP(1, 54, 126, 1, divider);

        display->setFont(u8g2_font_4x6_tr);
        display->drawStr(7, 62, "Main Menu");

        // Drawing the left and right arrows
        display->drawXBMP(1, 56, 4, 7, left_arrow);
        // display->drawXBMP(123, 56, 4, 7, right_arrow);

        display->sendBuffer();
    }

    // Override the getType method to return STATIC_SCREEN
    ScreenType getType() const override
    {
        return STATIC_SCREEN;
    }
};

#endif