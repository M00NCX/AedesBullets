#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include "Texture.h"

class GameOverScreen {
public:
    GameOverScreen();
    void render();
    void handleMouse(int x, int y);
    void handleClick(int button, int state, int x, int y);
private:
    Texture background;
    Texture restartButton;
    bool hoverRestart;

    void renderTexture(Texture& texture, int x, int y, int width, int height, bool hover);
};

#endif
