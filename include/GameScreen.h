#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Texture.h"
#include "Character.h"
#include "Mosquito.h"

class GameScreen {
public:
    GameScreen();
    void render();
private:
    Texture background;
    Character character;
    Mosquito mosquito;
};

#endif
