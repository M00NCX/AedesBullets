#ifndef CHARACTER_H
#define CHARACTER_H

#include "Texture.h"

class Character {
public:
    Character();
    void render(int pose); // Renderiza o personagem com a pose especificada
private:
    Texture spriteSheet; // Textura contendo todas as poses do personagem
};

#endif
