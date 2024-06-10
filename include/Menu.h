#ifndef MENU_H
#define MENU_H

#include "Texture.h"
#include "Mouse.h"

class Menu {
public:
    Texture background, logo, playButton, helpButton, exitButton;
    bool hoverPlay, hoverHelp, hoverExit;

    Menu();
    void render();
    void handleMouse(Mouse& mouse);
    void handleClick(Mouse& mouse);

private:
    void renderTexture(Texture& texture, int x, int y, int width, int height, bool hover = false);
};

#endif // MENU_H
