#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Screen.h"
#include "ScreenManager.h"
#include <U8g2lib.h>
#include <vector>

class MenuScreen : public Screen
{
protected:
    std::vector<const char *> options;
    std::vector<int> linkedScreens; // Store the indices of the linked screens in ScreenManager
    int selectedIndex;
    ScreenManager *screenManager;

public:
    MenuScreen(ScreenManager *manager, const std::vector<const char *> &opts, const std::vector<int> &links)
        : options(opts), linkedScreens(links), selectedIndex(0), screenManager(manager) {}

    virtual void show(U8G2 *display) = 0; // Pure virtual function, must be implemented in derived classes

    void nextOption()
    {
        selectedIndex = (selectedIndex + 1) % options.size(); // Cycle options
    }

    void prevOption()
    {
        selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
    }

    void selectOption()
    {
        if (selectedIndex < linkedScreens.size())
        {
            screenManager->switchToScreen(linkedScreens[selectedIndex]); // Switch to the linked screen
        }
    }

    // Override the getType method to return MENU_SCREEN
    ScreenType getType() const override
    {
        return MENU_SCREEN;
    }
};

#endif // MENUSCREEN_H
