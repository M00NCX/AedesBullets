#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <GL/gl.h>
#include "Texture.h"
#include "Character.h"
#include "Mosquito.h"
#include "Mosquito1.h"
#include "Mosquito2.h"
#include "Mosquito3.h"
#include "Map.h"

class GameScreen {
public:
    GameScreen();
    void render();
private:
    Texture background;
    Character character;
    Mosquito mosquito;
    Mosquito1 mosquito1;
    Mosquito2 mosquito2;
    Mosquito3 mosquito3;
    Map map;
};

#endif
