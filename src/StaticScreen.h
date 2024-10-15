#ifndef STATICSCREEN_H
#define STATICSCREEN_H

#include "Screen.h"
#include <U8g2lib.h>

class StaticScreen : public Screen
{
public:
    virtual void show(U8G2 *display) = 0; // Pure virtual function
};

#endif // STATICSCREEN_H
