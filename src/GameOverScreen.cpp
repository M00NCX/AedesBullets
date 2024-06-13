#include "GameOverScreen.h"
#include "Game.h"
#include <iostream>  // Para depuração

GameOverScreen::GameOverScreen() : 
    background("./img/background_gameover.jpeg"), 
    restartButton("./img/restart.png"), 
    hoverRestart(false) {}

void GameOverScreen::render() {
    // Renderiza o background
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    background.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(0, 0);
    glTexCoord2f(1, 1); glVertex2f(812, 0);
    glTexCoord2f(1, 0); glVertex2f(812, 588);
    glTexCoord2f(0, 0); glVertex2f(0, 588);
    glEnd();
    
    // Renderiza o botão de voltar (ajuste para 300x150)
    renderTexture(restartButton, 250, 200, 300, 150, hoverRestart);
    
    glDisable(GL_TEXTURE_2D);
}

void GameOverScreen::handleMouse(int x, int y) {
    // Note que y=0 está no topo da janela e y aumenta para baixo, então precisamos inverter a coordenada y

    // Coordenadas do botão
    int buttonXStart = 250;
    int buttonXEnd = buttonXStart + 300;
    int buttonYStart = 200;
    int buttonYEnd = buttonYStart + 150;

    // Ajuste para hoverBack
    hoverRestart = (x >= buttonXStart && x <= buttonXEnd && y >= buttonYStart && y <= buttonYEnd);
}

void GameOverScreen::handleClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && hoverRestart) {
        Game::getInstance().setState(GameState::MENU);
    }
}

void GameOverScreen::renderTexture(Texture& texture, int x, int y, int width, int height, bool hover) {
    if (hover) glColor3f(0.7f, 0.7f, 0.7f); // Darken if hovered
    else glColor3f(1.0f, 1.0f, 1.0f); // Normal color if not hovered
    
    glEnable(GL_TEXTURE_2D);
    texture.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(x, y);
    glTexCoord2f(1, 1); glVertex2f(x + width, y);
    glTexCoord2f(1, 0); glVertex2f(x + width, y + height);
    glTexCoord2f(0, 0); glVertex2f(x, y + height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
