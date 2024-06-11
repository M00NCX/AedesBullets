// Shot.cpp

#include "Shot.h"
#include <GL/glut.h>

Shot::Shot(float startX, float startY, float dirX, float dirY, float spd) :
    x(startX), y(startY), directionX(dirX), directionY(dirY), speed(spd) {}

void Shot::update(float deltaTime) {
    x += directionX * speed * deltaTime;
    y += directionY * speed * deltaTime;
}

void Shot::render() {
    glColor3f(0.0f, 0.0f, 0.0f); // Cor preta para o tiro
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

bool Shot::isOutOfBound() const {
    // Implemente a lógica para verificar se o tiro está fora dos limites da tela
    // Aqui está um exemplo básico que verifica apenas se o tiro está muito longe da tela
    return x < 0 || x > 800 || y < 0 || y > 600;
}
