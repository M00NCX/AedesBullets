#ifndef MOSQUITO_H
#define MOSQUITO_H

#include "Texture.h"

class Mosquito {
public:
    Texture spriteSheet;
    float x, y;

    Mosquito(float startX, float startY);
    void render();
    void update(float deltaTime);
};

#endif // MOSQUITO_H
