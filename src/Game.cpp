#include "Game.h"
#include "Character.h"

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
        character.resetPoints();
        mosquito.resetPosition();

        mosquito.setVisible(true);

        mosquito1.resetPosition();

        mosquito1.setVisible(true);

        mosquito2.resetPosition();

        mosquito2.setVisible(true);

        mosquito3.resetPosition();

        mosquito3.setVisible(true);
    }
    else
    {
        mosquito.setVisible(false);

        mosquito1.setVisible(false);

        mosquito2.setVisible(false);

        mosquito3.setVisible(false);
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
        mosquito.render(0); 
        mosquito2.render(0);
        mosquito3.render(0);
        mosquito1.render(0);// Renderizar o personagem na pose 0 (ajustar conforme necessário)
        // Verifica colisão entre mosquito e personagem
        character.renderProjectiles();
        if (mosquito.checkCollision(character.getX(), character.getY(), character.getWidth(), character.getHeight()))
        {
            // Houve colisão, o personagem perde uma vida
            character.loseLife();

            // Verifica se o jogador ainda tem vidas
            if (character.getLives() <= 0)
            {
                // Aqui você pode implementar a lógica de game over
                setState(GameState::GAMEOVER); // Volta para o menu após o game over
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
        // Renderiza o número de pontos na tela
        {
            int points = character.showPoints();
            std::string pointsText = "Pontos: " + std::to_string(points);

            glColor3f(1.0f, 1.0f, 1.0f); // Cor branca
            glMatrixMode(GL_PROJECTION);
            glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, Character::getScreenWidth(), 0, Character::getScreenHeight()); // Ajuste para usar os métodos estáticos
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glLoadIdentity();

            // Posição para renderizar o número de pontos (por exemplo, canto inferior esquerdo)
            glRasterPos2i(100, 20); // Ajuste a posição conforme necessário
            for (const char &c : pointsText)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); // Use a fonte desejada
            }

            glPopMatrix();
            glMatrixMode(GL_PROJECTION);
            glPopMatrix();
            glMatrixMode(GL_MODELVIEW);
        }

        // Renderiza o aviso de foco de dengue na tela
        if (character.isFoco(character.getX(), character.getY(), getMap())){
            std::string pointsText = "Voce esta sobre um ponto de foco de dengue, pressione G para trata-lo!";

            glColor3f(1.0f, 0.5f, 0.5f); // Cor branca
            glMatrixMode(GL_PROJECTION);
            glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, Character::getScreenWidth(), 0, Character::getScreenHeight()); // Ajuste para usar os métodos estáticos
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glLoadIdentity();

            // Posição para renderizar o texto (por exemplo, canto inferior esquerdo)
            glRasterPos2i(205, 20); // Ajuste a posição conforme necessário
            for (const char &c : pointsText)
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
    case GameState::GAMEOVER:
        gameOverScreen.render(); // Renderizar o fundo do jogo
        // Aqui, adicione a renderização do menu de pausa
        // pauseMenu.render();
        break;
    case GameState::WINNER:
        winnerScreen.render(); // Renderizar o fundo do jogo
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

Map Game::getMap() const
{
    return map;
}

Mosquito &Game::getMosquito()
{
    return mosquito;
}

Mosquito1 &Game::getMosquito1()
{
    return mosquito1;
}

Mosquito2 &Game::getMosquito2()
{
    return mosquito2;
}

Mosquito3 &Game::getMosquito3()
{
    return mosquito3;
}

GameState Game::getState() const
{
    return state;
}

void Game::update() {
    if (state == GameState::PLAY) {
        character.updateProjectiles();
    }
}