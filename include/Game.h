#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "GameScreen.h"
#include "Mouse.h"
#include "HelpScreen.h"
#include "GameOverScreen.h"
#include "Map.h"
#include "Mosquito.h" // Certifique-se de incluir o cabeçalho correto do Mosquito

enum class GameState
{
    MENU,
    PLAY,
    HELP,
    PAUSE,
    GAMEOVER
};

class Game
{
private:
    GameState state;
    Menu menu;
    GameScreen gameScreen;
    HelpScreen helpScreen;
    GameOverScreen gameOverScreen;
    Mouse mouse;
    Character character;
    Mosquito mosquito;
    Map map;

    Game();

public:
    static Game &getInstance();
    void setState(GameState newState);
    void togglePause(); // Método para alternar entre pausado e não pausado
    void render();
    void handleMouseMotion(int x, int y);
    void handleMouseClick(int button, int state, int x, int y);
    void handleKeyPress(unsigned char key, int x, int y); // Método para tratar teclas de atalho
    Character &getCharacter();
    Mosquito &getMosquito();    // Novo método para acessar o mosquito
    GameState getState() const; // Novo método para acessar o estado do jogo
    Map &getMap();
};

#endif // GAME_H
