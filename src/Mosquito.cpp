#include "Mosquito.h"
#include <iostream>

Mosquito::Mosquito() : spriteSheet("./img/mosquito.png"), x(700.0f), y(100.0f) {} // Posição inicial centralizada

void Mosquito::render(int pose) {
    // Determina as coordenadas de textura para a pose específica
    float poseWidth = 1.0f;
    float poseHeight = 1.0f;
    float poseOffset = pose * poseWidth;

    // Renderiza a pose específica do personagem
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    spriteSheet.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(poseOffset, 1); glVertex2f(x, y);
    glTexCoord2f(poseOffset + poseWidth, 1); glVertex2f(x + 100, y); // Supondo uma largura de 100 pixels para o personagem
    glTexCoord2f(poseOffset + poseWidth, 0); glVertex2f(x + 100, y + 200); // Supondo uma altura de 200 pixels para o personagem
    glTexCoord2f(poseOffset, 0); glVertex2f(x, y + 200);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

