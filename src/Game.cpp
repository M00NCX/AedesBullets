#include "Game.h"

Game::Game() : state(GameState::MENU) {}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::setState(GameState newState)
{
    state = newState;
    if (state == GameState::PLAY)
    {
        mosquito.setVisible(true);
    }
    else
    {
        mosquito.setVisible(false);
    }
}

void Game::togglePause()
{
    if (state == GameState::PAUSE)
    {
        setState(GameState::PLAY);
    }
    else if (state == GameState::PLAY)
    {
        setState(GameState::PAUSE);
    }
}

void Game::render()
{
    switch (state)
    {
    case GameState::MENU:
        menu.render();
        break;
    case GameState::PLAY:
        gameScreen.render();
        character.render(0);
        mosquito.render(0); // Renderizar o personagem na pose 0 (ajustar conforme necessário)
        break;
    case GameState::HELP:
        helpScreen.render();
        break;
    case GameState::PAUSE:
        helpScreen.render(); // Renderizar o fundo do jogo
        // Aqui, adicione a renderização do menu de pausa
        // pauseMenu.render();
        break;
    }
}

void Game::handleMouseMotion(int x, int y)
{
    mouse.updatePosition(x, y);
    switch (state)
    {
    case GameState::MENU:
        menu.handleMouse(mouse);
        break;
    case GameState::PLAY:
        // Lógica para o jogo
        break;
    case GameState::HELP:
        helpScreen.render();
        break;
    case GameState::PAUSE:
        // Lógica para o menu de pausa
        break;
    }
}

void Game::handleMouseClick(int button, int state, int x, int y)
{
    mouse.updatePosition(x, y);
    mouse.handleButton(button, state);
    if (mouse.leftButtonDown)
    {
        switch (this->state)
        { // Corrigir variável oculta
        case GameState::MENU:
            menu.handleClick(mouse);
            break;
        case GameState::PLAY:
            // Lógica para o jogo
            break;
        case GameState::HELP:
            helpScreen.render();
            break;
        case GameState::PAUSE:
            // Lógica para o menu de pausa
            break;
        }
    }
}

Character &Game::getCharacter()
{
    return character;
}

Map &Game::getMap()
{
    return map;
}

Mosquito &Game::getMosquito()
{
    return mosquito;
}

GameState Game::getState() const
{
    return state;
}
