#include "Projectile.h"

Projectile::Projectile(float startX, float startY)
    : spritesheet("./img/poder2.png"), x(startX), y(startY), speed(10.0f) {}

void Projectile::render() {
    float width = 40.0f; // Largura do projétil
    float height = 10.0f; // Altura do projétil

    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    spritesheet.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(x, y);
    glTexCoord2f(1, 1); glVertex2f(x + width, y);
    glTexCoord2f(1, 0); glVertex2f(x + width, y + height);
    glTexCoord2f(0, 0); glVertex2f(x, y + height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Projectile::update() {
    if (goingRight) {
        x += speed;
    } else {
        x -= speed;
    }
}

bool Projectile::isOffScreen() const {
    return x > 812;
}

float Projectile::getX() const {
    return x;
}

float Projectile::getY() const {
    return y;
}

float Projectile::getWidth() const {
    return 50.0f;
}

float Projectile::getHeight() const {
    return 20.0f;
}
