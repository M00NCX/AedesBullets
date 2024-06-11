#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "GameScreen.h"
#include "Mouse.h"
#include "HelpScreen.h"

enum class GameState { MENU, PLAY, HELP };

class Game {
private:
    GameState state;
    Menu menu;
    GameScreen gameScreen;
    HelpScreen helpScreen;
    Mouse mouse;

    Game();

public:
    static Game& getInstance();
    void setState(GameState newState);
    void render();
    void handleMouseMotion(int x, int y);
    void handleMouseClick(int button, int state, int x, int y);
};

#endif // GAME_H
