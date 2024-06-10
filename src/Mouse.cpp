#include "Mouse.h"
#include <GL/glut.h>

Mouse::Mouse() : x(0), y(0), leftButtonDown(false) {}

void Mouse::updatePosition(int newX, int newY) {
    x = newX;
    y = 600 - newY;  // Corrige a coordenada y
}

void Mouse::handleButton(int button, int state) {
    if (button == GLUT_LEFT_BUTTON) {
        leftButtonDown = (state == GLUT_DOWN);
    }
}

void Mouse::setCursor(bool hover) {
    if (hover) {
        glutSetCursor(GLUT_CURSOR_INFO);
    } else {
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    }
}
