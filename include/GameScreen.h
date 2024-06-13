#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <GL/gl.h>
#include "Texture.h"
#include "Character.h"
#include "Mosquito.h"
#include "Map.h"

class GameScreen {
public:
    GameScreen();
    void render();
private:
    Texture background;
    Character character;
    Mosquito mosquito;
    Map map;
};

#endif
