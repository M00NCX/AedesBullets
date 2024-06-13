#include "Mosquito.h"
#include <iostream>

Mosquito::Mosquito() : spriteSheet("./img/mosquito.png"), x(700), y(100), visible(false), direction(-1)
{
    srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios
    initialX = x;
    initialY = y;
}


void Mosquito::render(int pose)
{
    if (!visible)
        return; // Se o mosquito não estiver visível, não renderiza

    // Determina as coordenadas de textura para a pose específica
    float poseWidth = 1.0f;
    float poseHeight = 1.0f;
    float poseOffset = pose * poseWidth;

    // Renderiza a pose específica do mosquito
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    spriteSheet.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(poseOffset, 1);
    glVertex2f(x, y);
    glTexCoord2f(poseOffset + poseWidth, 1);
    glVertex2f(x + 50, y);
    glTexCoord2f(poseOffset + poseWidth, 0);
    glVertex2f(x + 50, y + 50);
    glTexCoord2f(poseOffset, 0);
    glVertex2f(x, y + 50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Mosquito::movimentacao()
{
    if (!visible)
        return; // Se o mosquito não estiver visível, não se move

    // Gera um deslocamento aleatório no intervalo [-10, 10]
    float deltaX = direction * (rand() % 20); // Randômico entre 0 e 10

    // Atualiza a posição do mosquito
    x += deltaX;

    // Limita o movimento para ficar dentro da tela na horizontal (assumindo tamanho da tela 800x600)
    if (x < 0)
    {
        x = 0;
        direction = 1; // Muda a direção para direita
    }
    else if (x > 800 - 100)
    {
        x = 800 - 100;  // Assumindo largura do mosquito 100 pixels
        direction = -1; // Muda a direção para esquerda
    }
}

void Mosquito::setVisible(bool visible)
{
    this->visible = visible;
}

bool Mosquito::checkCollision(float x, float y, float width, float height)
{
    // Dimensões da imagem do mosquito (ajustar conforme necessário)
    float mosquitoWidth = 15.0f;
    float mosquitoHeight = 15.0f;

    // Limites do mosquito na tela
    float myLeft = this->x;
    float myRight = this->x + mosquitoWidth;
    float myTop = this->y;
    float myBottom = this->y + mosquitoHeight;

    // Limites do outro objeto (por exemplo, personagem)
    float otherLeft = x;
    float otherRight = x + width;
    float otherTop = y;
    float otherBottom = y + height;

    // Verifica colisão nas coordenadas X e Y
    bool collisionX = myRight >= otherLeft && myLeft <= otherRight;
    bool collisionY = myBottom >= otherTop && myTop <= otherBottom;

    return collisionX && collisionY;
}

void Mosquito::resetPosition()
{
    x = initialX;
    y = initialY;
}