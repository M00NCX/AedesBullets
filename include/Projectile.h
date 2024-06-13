#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Texture.h"

class Projectile {
public:
    Projectile(float startX, float startY);
    void render();  // Renderiza o projétil
    void update();  // Atualiza a posição do projétil
    bool isOffScreen() const; // Verifica se o projétil está fora da tela
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

private:
    Texture spritesheet;
    float x, y;      // Posição do projétil
    float speed;     // Velocidade do projétil
    bool goingRight;
};

#endif
