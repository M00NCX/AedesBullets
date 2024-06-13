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
        character.resetLives();
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
        map.loadMap("./src/Fase2.txt");
        mosquito.render(0); // Renderizar o personagem na pose 0 (ajustar conforme necessário)
        // Verifica colisão entre mosquito e personagem
        if (mosquito.checkCollision(character.getX(), character.getY(), character.getWidth(), character.getHeight()))
        {
            // Houve colisão, o personagem perde uma vida
            character.loseLife();

            // Verifica se o jogador ainda tem vidas
            if (character.getLives() <= 0)
            {
                // Aqui você pode implementar a lógica de game over
                setState(GameState::MENU); // Volta para o menu após o game over
            }
        }

        // Renderiza o número de vidas na tela
        {
            int lives = character.getLives();
            std::string livesText = "Lives: " + std::to_string(lives);

            glColor3f(1.0f, 1.0f, 1.0f); // Cor branca
            glMatrixMode(GL_PROJECTION);
            glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, Character::getScreenWidth(), 0, Character::getScreenHeight()); // Ajuste para usar os métodos estáticos
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glLoadIdentity();

            // Posição para renderizar o número de vidas (por exemplo, canto inferior esquerdo)
            glRasterPos2i(10, 20); // Ajuste a posição conforme necessário
            for (const char &c : livesText)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); // Use a fonte desejada
            }

            glPopMatrix();
            glMatrixMode(GL_PROJECTION);
            glPopMatrix();
            glMatrixMode(GL_MODELVIEW);
        }
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
