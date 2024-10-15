#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <U8g2lib.h>
#include "Screen.h"
#include <vector>

class ScreenManager
{
private:
    U8G2 *display;
    std::vector<Screen *> screens;
    int currentScreenIndex;

public:
    ScreenManager(U8G2 *u8g2) : display(u8g2), currentScreenIndex(0) {}

    void init();   // Initialize the screens
    void update(); // Update current screen

    void addScreen(Screen *screen);
    void nextScreen();                    // Go to the next screen
    void prevScreen();                    // Go to the previous screen
    void switchToScreen(int screenIndex); // New method to switch to a specific screen

    Screen *getCurrentScreen(); // Method to return the current active screen
};

#endif // SCREENMANAGER_H
