#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "GameScreen.h"
#include "Mouse.h"
#include "HelpScreen.h"
#include "GameOverScreen.h"
#include "WinnerScreen.h"
#include "Map.h"
#include "Mosquito.h" // Certifique-se de incluir o cabeçalho correto do Mosquito
#include "Mosquito1.h"
#include "Mosquito2.h"
#include "Mosquito3.h"


enum class GameState
{
    MENU,
    PLAY,
    HELP,
    PAUSE,
    GAMEOVER,
    WINNER
};

class Game
{
private:
    GameState state;
    Menu menu;
    GameScreen gameScreen;
    HelpScreen helpScreen;
    GameOverScreen gameOverScreen;
    WinnerScreen winnerScreen;
    Mouse mouse;
    Character character;
    Mosquito mosquito;
    Mosquito1 mosquito1;
    Mosquito2 mosquito2;
    Mosquito3 mosquito3;
    Map map;

    Game();

public:
    static Game &getInstance();
    void setState(GameState newState);
    void togglePause(); // Método para alternar entre pausado e não pausado
    void render();
    void handleMouseMotion(int x, int y);
    void handleMouseClick(int button, int state, int x, int y);
    Character &getCharacter();
    Mosquito &getMosquito();    // Novo método para acessar o mosquito
    Mosquito1 &getMosquito1();
    Mosquito2 &getMosquito2();
    Mosquito3 &getMosquito3();
    GameState getState() const; // Novo método para acessar o estado do jogo
    Map &getMap();
    void update(); // Novo método para atualizar o jogo
};

#endif // GAME_H
