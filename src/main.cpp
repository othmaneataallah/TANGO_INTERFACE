#include <Arduino.h>
#include "ScreenManager.h"
#include "Screens/InitialScreen.h"
#include "Screens/MainMenuScreen.h"
#include "Screens/ITCScreen.h"
#include <U8g2lib.h>

// Define the OLED Pins
#define OLED_CS 5
#define OLED_DC 2
#define OLED_RESET 4

U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2(U8G2_R0, OLED_CS, OLED_DC, OLED_RESET);

// Global ScreenManager
ScreenManager screenManager(&u8g2);

// Define button pins
#define PREVIOUS_BUTTON 6
#define NEXT_BUTTON 6
#define SELECT_BUTTON 7

bool LOL = true;

void setup()
{
  u8g2.begin();
  screenManager.init(); // Initialize and load the first screen

  InitialScreen *welcomeScreen = new InitialScreen();

  ITCScreen *itcScreen = new ITCScreen();

  // Create menu screen with links to the 3 other screens
  std::vector<const char *> menuOptions = {"IT Community"};
  std::vector<int> linkedScreens = {2}; // Corresponding indices in ScreenManager
  MainMenuScreen *mainMenuScreen = new MainMenuScreen(&screenManager, menuOptions, linkedScreens);

  screenManager.addScreen(welcomeScreen);
  screenManager.addScreen(mainMenuScreen);
  screenManager.addScreen(new ITCScreen());
}

void loop()
{
  screenManager.update(); // Refresh the current screen

  if (LOL)
  {
    delay(3000);
    screenManager.switchToScreen(1); // Switch to the main menu screen
    delay(3000);
    LOL = false;
    Screen *currentScreen = screenManager.getCurrentScreen();
    if (currentScreen->getType() == MENU_SCREEN)
    {
      MenuScreen *currentMenu = static_cast<MenuScreen *>(currentScreen);
      currentMenu->selectOption(); // Select the current menu option and switch to the linked screen
    }
  }
}
