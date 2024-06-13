#ifndef MOSQUITO_H
#define MOSQUITO_H

#include "Texture.h"
#include <cstdlib>
#include <ctime>
class Mosquito
{
public:
    Mosquito();
    void render(int pose); // Renderiza o personagem com a pose especificada
    void movimentacao();   // Atualiza a posição do mosquito
    void setVisible(bool visible);
    bool checkCollision(float x, float y, float width, float height); // Declaração da função
    void resetPosition();                                             // Reseta a posição inicial do mosquito

private:
    Texture spriteSheet; // Textura contendo todas as poses do personagem
    float x, y;          // Posição do personagem
    bool visible;        // Indica se o mosquito está visível
    int direction;       // 1 para direita, -1 para esquerda
    float initialX;      // Posição inicial em x
    float initialY;      // Posição inicial em y
};

#endif
