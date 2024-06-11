#include <GL/glut.h>
#include "Game.h"
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Game::getInstance().render();
    glutSwapBuffers();
}

void passiveMotion(int x, int y) {
    Game::getInstance().handleMouseMotion(x, y);
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    Game::getInstance().handleMouseClick(button, state, x, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    std::cout << "Key pressed: " << key << std::endl;
    float distance = 10.0f; // Distância que o personagem vai se mover
    switch (key) {
        case 27: // ESC key
            Game::getInstance().togglePause();
            break;
        case 'w':
        case 'W':
            Game::getInstance().getCharacter().moveUp(distance);
            break;
        case 's':
        case 'S':
            Game::getInstance().getCharacter().moveDown(distance);
            break;
        case 'a':
        case 'A':
            Game::getInstance().getCharacter().moveLeft(distance);
            break;
        case 'd':
        case 'D':
            Game::getInstance().getCharacter().moveRight(distance);
            break;
    }
    glutPostRedisplay();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Fundo branco
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Aedes Combat: Viagem pelas estacoes.");
    
    init();

    glutDisplayFunc(display);
    glutPassiveMotionFunc(passiveMotion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); // Adicionar manipulador de teclado

    glutMainLoop();
    return 0;
}
