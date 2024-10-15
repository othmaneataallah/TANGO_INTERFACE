#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "MenuScreen.h"
#include <U8g2lib.h>

class MainMenuScreen : public MenuScreen
{
public:
    MainMenuScreen(ScreenManager *manager, const std::vector<const char *> &opts, const std::vector<int> &links)
        : MenuScreen(manager, opts, links) {}

    void show(U8G2 *display) override
    {
        display->clearBuffer();
        display->setFont(u8g2_font_ncenB08_tr);
        for (size_t i = 0; i < options.size(); ++i)
        {
            if (i == selectedIndex)
            {
                display->drawBox(0, 12 * i, 128, 12); // Highlight selected option
                display->setDrawColor(0);             // Invert text color for selected option
            }
            display->drawStr(5, 12 * i + 10, options[i]);
            display->setDrawColor(1); // Reset to normal color
        }
        display->sendBuffer();
    }
    // Override the getType method to return STATIC_SCREEN
    ScreenType getType() const override
    {
        return MENU_SCREEN;
    }
};

#endif // SIMPLEMENUSCREEN_H