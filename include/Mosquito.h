#ifndef MOSQUITO_H
#define MOSQUITO_H

#include "Texture.h"
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

class Mosquito
{
public:
    Mosquito();
    void render(int pose);                                            // Renderiza o personagem com a pose especificada
    void movimentacao();                                              // Atualiza a posição do mosquito
    void setVisible(bool visible);                                    // Define se o mosquito está visível ou não
    bool checkCollision(float x, float y, float width, float height); // Declaração da função

private:
    Texture spriteSheet; // Textura contendo todas as poses do personagem
    float x, y;          // Posição do personagem
    bool visible;        // Indica se o mosquito está visível
    int direction;       // 1 para direita, -1 para esquerda
};

#endif
