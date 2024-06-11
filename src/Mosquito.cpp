#include "Mosquito.h"

Mosquito::Mosquito(float startX, float startY)
    : spriteSheet("./img/mosquito.png"), x(startX), y(startY) {}

void Mosquito::render() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    spriteSheet.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(x, y);
    glTexCoord2f(1, 1); glVertex2f(x + 50, y); // Largura de 50 pixels
    glTexCoord2f(1, 0); glVertex2f(x + 50, y + 50); // Altura de 50 pixels
    glTexCoord2f(0, 0); glVertex2f(x, y + 50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Mosquito::update(float deltaTime) {
    x -= 100 * deltaTime; // Mover para a esquerda a uma velocidade de 100 pixels por segundo
}
