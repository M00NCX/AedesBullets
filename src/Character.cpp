#include "Character.h"
#include <iostream>

Character::Character() : spriteSheet("./img/goku.png") {}

void Character::render(int pose) {
    // Determina as coordenadas de textura para a pose específica
    // Suponha que o sprite sheet tenha 4 poses, cada uma ocupando 25% da largura da textura
    float poseWidth = 1.0f;
    float poseHeight = 1.0f; // Supondo que a altura da pose seja igual à altura da textura
    float poseOffset = pose;

    // Renderiza a pose específica do personagem
    glColor3f(1.0f, 1.0f, 1.0f); // Define a cor para branco para garantir que a textura seja renderizada com suas cores originais
    glEnable(GL_TEXTURE_2D);
    spriteSheet.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(poseOffset, 1); glVertex2f(0, 0);
    glTexCoord2f(poseOffset + poseWidth, 1); glVertex2f(70, 0); // Supondo uma largura de 100 pixels para o personagem
    glTexCoord2f(poseOffset + poseWidth, 0); glVertex2f(70, 100); // Supondo uma altura de 200 pixels para o personagem
    glTexCoord2f(poseOffset, 0); glVertex2f(0, 100);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
