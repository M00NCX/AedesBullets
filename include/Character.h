#ifndef CHARACTER_H
#define CHARACTER_H

#include "Texture.h"

class Character {
public:
    Character();
    void render(int pose); // Renderiza o personagem com a pose especificada
    void moveUp(float distance); // Movimento para cima
    void moveDown(float distance); // Movimento para baixo
    void moveLeft(float distance); // Movimento para a esquerda
    void moveRight(float distance); // Movimento para a direita
private:
    Texture spriteSheet; // Textura contendo todas as poses do personagem
    float x, y; // Posição do personagem
};

#endif
