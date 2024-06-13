#include "Mosquito.h"
#include <iostream>

Mosquito::Mosquito() : spriteSheet("./img/mosquito.png"), x(700.0f), y(100.0f), visible(false), direction(-1)
{
    srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios
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
    glVertex2f(x + 50, y); // Supondo uma largura de 100 pixels para o personagem
    glTexCoord2f(poseOffset + poseWidth, 0);
    glVertex2f(x + 50, y + 100); // Supondo uma altura de 200 pixels para o personagem
    glTexCoord2f(poseOffset, 0);
    glVertex2f(x, y + 100);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Mosquito::movimentacao()
{
    if (!visible)
        return; // Se o mosquito não estiver visível, não se move

    // Gera um deslocamento aleatório no intervalo [-10, 10]
    float deltaX = direction * (rand() % 11); // Randômico entre 0 e 10

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
