#include "HelpScreen.h"
#include "Game.h"
#include <iostream>  // Para depuração

HelpScreen::HelpScreen() : 
    background("./img/background_ajuda.png"), 
    backButton("./img/back.png"), 
    hoverBack(false) {}

void HelpScreen::render() {
    // Renderiza o background
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    background.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(0, 0);
    glTexCoord2f(1, 1); glVertex2f(800, 0);
    glTexCoord2f(1, 0); glVertex2f(800, 600);
    glTexCoord2f(0, 0); glVertex2f(0, 600);
    glEnd();
    
    // Renderiza o botão de voltar (ajuste para 300x150)
    renderTexture(backButton, -80, 470, 300, 150, hoverBack);
    
    glDisable(GL_TEXTURE_2D);
}

void HelpScreen::handleMouse(int x, int y) {
    // Note que y=0 está no topo da janela e y aumenta para baixo, então precisamos inverter a coordenada y
    y = 600 - y; // Ajuste para coordenadas de tela

    // Coordenadas do botão
    int buttonXStart = -80;
    int buttonXEnd = buttonXStart + 300;
    int buttonYStart = 470;
    int buttonYEnd = buttonYStart + 150;

    // Ajuste para hoverBack
    hoverBack = (x >= buttonXStart && x <= buttonXEnd && y >= buttonYStart && y <= buttonYEnd);
    std::cout << "Mouse move: " << x << ", " << y << " Hover: " << hoverBack << std::endl;  // Para depuração
}

void HelpScreen::handleClick(int button, int state, int x, int y) {
    y = 600 - y;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && hoverBack) {
        Game::getInstance().setState(GameState::MENU);
    }
}

void HelpScreen::renderTexture(Texture& texture, int x, int y, int width, int height, bool hover) {
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
