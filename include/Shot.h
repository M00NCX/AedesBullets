// Shot.h

#ifndef SHOT_H
#define SHOT_H

class Shot {
public:
    Shot(float startX, float startY, float dirX, float dirY, float spd);
    void update(float deltaTime);
    void render();
    bool isOutOfBound() const;

private:
    float x, y; // Posição do tiro
    float directionX, directionY; // Direção do tiro
    float speed; // Velocidade do tiro
};

#endif // SHOT_H
