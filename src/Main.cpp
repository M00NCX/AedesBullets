#include <GL/glut.h>
#include "Game.h"
#include <iostream>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Game::getInstance().render();
    glutSwapBuffers();
}

void passiveMotion(int x, int y)
{
    Game::getInstance().handleMouseMotion(x, y);
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    Game::getInstance().handleMouseClick(button, state, x, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    std::cout << "Key pressed: " << key << std::endl;
    float distance = 7.0f; // Distance the character will move
    auto& character = Game::getInstance().getCharacter();
    auto& map = Game::getInstance().getMap();

    switch (key)
    {
    case 27: // ESC key
        Game::getInstance().togglePause();
        break;
    case 'w':
    case 'W':
        character.moveUp(distance, map);
        break;
    case 's':
    case 'S':
        character.moveDown(distance, map);
        break;
    case 'a':
    case 'A':
        character.moveLeft(distance, map);
        break;
    case 'd':
    case 'D':
        character.moveRight(distance, map);
        break;
    }
    glutPostRedisplay();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 812, 0, 588);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fundo branco

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void timer(int value)
{
    Game &game = Game::getInstance();
    if (game.getState() == GameState::PLAY)
    {
        game.getMosquito().movimentacao(); // Atualiza a posição do mosquito
    }
    glutPostRedisplay();          // Redispara a renderização
    glutTimerFunc(100, timer, 0); // Redefine o temporizador para 100ms
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(812, 588);
    glutCreateWindow("Aedes Combat: Viagem pelas estacoes.");

    init();

    glutDisplayFunc(display);
    glutPassiveMotionFunc(passiveMotion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);   // Adicionar manipulador de teclado
    glutTimerFunc(100, timer, 0); // Inicializa o temporizador para movimentação do mosquito

    glutMainLoop();
    return 0;
}
