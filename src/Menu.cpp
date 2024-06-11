#include "Menu.h"
#include "Game.h"
#include <iostream>

Menu::Menu() : 
    background("./img/background_menu.jpg"), 
    logo("./img/logo.png"), 
    playButton("./img/play.png"), 
    helpButton("./img/help.png"), 
    exitButton("./img/exit.png"), 
    hoverPlay(false), 
    hoverHelp(false), 
    hoverExit(false) {}

void Menu::render() {
    // Renderiza background (tamanho original)
    renderTexture(background, 0, 0, 800, 600);

    // Renderiza logo (aumentando o tamanho para 300x150)
    renderTexture(logo, 150, 345, 500, 250);

    // Renderiza botões (aumentando o tamanho para 150x75)
    renderTexture(playButton, 265, 200, 300, 150, hoverPlay);
    renderTexture(helpButton, 265, 150, 300, 150, hoverHelp);
    renderTexture(exitButton, 265, 70, 300, 150, hoverExit);
}

void Menu::handleMouse(Mouse& mouse) {
    hoverPlay = (mouse.x >= 325 && mouse.x <= 475 && mouse.y >= 275 && mouse.y <= 350);
    hoverHelp = (mouse.x >= 325 && mouse.x <= 475 && mouse.y >= 175 && mouse.y <= 250);
    hoverExit = (mouse.x >= 325 && mouse.x <= 475 && mouse.y >= 75 && mouse.y <= 150);

    mouse.setCursor(hoverPlay || hoverHelp || hoverExit);
}

void Menu::handleClick(Mouse& mouse) {
    if (hoverPlay) {
        // Muda para a tela de jogo
        Game::getInstance().setState(GameState::PLAY);
    } else if (hoverHelp) {
        // Muda para a tela de jogo
        Game::getInstance().setState(GameState::HELP);
    } else if (hoverExit) {
        // Sai do jogo
        exit(0);
    }
}

void Menu::renderTexture(Texture& texture, int x, int y, int width, int height, bool hover) {
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
