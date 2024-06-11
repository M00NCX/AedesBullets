#ifndef MOSQUITO_H
#define MOSQUITO_H

#include "Texture.h"

class Mosquito {
public:
    Mosquito();
    void render(int pose); // Renderiza o personagem com a pose especificada
private:
    Texture spriteSheet; // Textura contendo todas as poses do personagem
    float x, y; // Posição do personagem
};

#endif
