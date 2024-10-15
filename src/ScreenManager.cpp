#include "ScreenManager.h"

void ScreenManager::init()
{
    if (!screens.empty())
    {
        screens[currentScreenIndex]->show(display);
    }
}

void ScreenManager::update()
{
    if (!screens.empty())
    {
        screens[currentScreenIndex]->show(display);
    }
}

void ScreenManager::addScreen(Screen *screen)
{
    screens.push_back(screen);
}

void ScreenManager::nextScreen()
{
    currentScreenIndex = (currentScreenIndex + 1) % screens.size(); // Cycle through screens
}

void ScreenManager::prevScreen()
{
    currentScreenIndex = (currentScreenIndex - 1 + screens.size()) % screens.size();
}

void ScreenManager::switchToScreen(int screenIndex)
{
    if (screenIndex >= 0 && screenIndex < screens.size())
    {
        currentScreenIndex = screenIndex;
        screens[currentScreenIndex]->show(display);
    }
}

Screen *ScreenManager::getCurrentScreen()
{
    return screens[currentScreenIndex]; // Return the current active screen
}