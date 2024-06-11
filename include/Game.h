#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "GameScreen.h"
#include "Mouse.h"
#include "HelpScreen.h"
#include "MosquitoManager.h"

enum class GameState { MENU, PLAY, HELP, PAUSE };

class Game {
private:
    GameState state;
    Menu menu;
    GameScreen gameScreen;
    HelpScreen helpScreen;
    Mouse mouse;
    Character character;
    Mosquito mosquito;

    Game();

public:
    static Game& getInstance();
    void setState(GameState newState);
    void togglePause(); // Método para alternar entre pausado e não pausado
    void render();
    void handleMouseMotion(int x, int y);
    void handleMouseClick(int button, int state, int x, int y);
    void handleKeyPress(unsigned char key, int x, int y); // Método para tratar teclas de atalho
    Character& getCharacter();
};

#endif // GAME_H
