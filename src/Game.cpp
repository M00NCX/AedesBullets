#include "Game.h"

Game::Game() : state(GameState::MENU) {}

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::setState(GameState newState) {
    state = newState;
}

void Game::render() {
    switch (state) {
        case GameState::MENU:
            menu.render();
            break;
        case GameState::PLAY:
            gameScreen.render();
            break;
    }
}

void Game::handleMouseMotion(int x, int y) {
    mouse.updatePosition(x, y);
    switch (state) {
        case GameState::MENU:
            menu.handleMouse(mouse);
            break;
        case GameState::PLAY:
            // Lógica para o jogo
            break;
    }
}

void Game::handleMouseClick(int button, int state, int x, int y) {
    mouse.updatePosition(x, y);
    mouse.handleButton(button, state);
    if (mouse.leftButtonDown) {
        switch (state) {
            case GameState::MENU:
                menu.handleClick(mouse);
                break;
            case GameState::PLAY:
                // Lógica para o jogo
                break;
        }
    }
}
