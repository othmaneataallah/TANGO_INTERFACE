#ifndef SCREEN_H
#define SCREEN_H

#include <U8g2lib.h>

enum ScreenType
{
    STATIC_SCREEN,
    MENU_SCREEN
};

class Screen
{
public:
    virtual ~Screen() {}
    virtual void show(U8G2 *display) = 0;   // Pure virtual method
    virtual ScreenType getType() const = 0; // New method to return the type of the screen
};

#endif // SCREEN_H
