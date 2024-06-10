#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen() : background("./img/background_mapa1.jpg") {}

void GameScreen::render() {
    // Renderiza background
    glColor3f(1.0f, 1.0f, 1.0f); // Define a cor para branco para garantir que a textura seja renderizada com suas cores originais
    glEnable(GL_TEXTURE_2D);
    background.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(0, 0);
    glTexCoord2f(1, 1); glVertex2f(800, 0);
    glTexCoord2f(1, 0); glVertex2f(800, 600);
    glTexCoord2f(0, 0); glVertex2f(0, 600);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
