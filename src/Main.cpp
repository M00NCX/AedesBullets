#include <GL/glut.h>
#include "Game.h"

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

    glutMainLoop();
    return 0;
}
