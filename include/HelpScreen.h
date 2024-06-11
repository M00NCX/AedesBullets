#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include "Texture.h"

class HelpScreen {
public:
    HelpScreen();
    void render();
    void handleMouse(int x, int y);
    void handleClick(int button, int state, int x, int y);
private:
    Texture background;
    Texture backButton;
    bool hoverBack;

    void renderTexture(Texture& texture, int x, int y, int width, int height, bool hover);
};

#endif
