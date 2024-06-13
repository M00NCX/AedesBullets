#include "Character.h"
#include <iostream>

Character::Character() : spriteSheet("./img/Goku2.png"), x(100.0f), y(110.0f), lives(3) {}

void Character::render(int pose)
{
    // Assuming the sprite sheet contains multiple poses in a row
    float poseWidth = 1.0f / 1; // Adjust this to the number of poses
    float poseHeight = 1.0f;
    float poseOffsetX = pose * poseWidth;

    // Render the specific pose of the character
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    spriteSheet.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(poseOffsetX, 1);
    glVertex2f(x, y);
    glTexCoord2f(poseOffsetX + poseWidth, 1);
    glVertex2f(x + width, y);
    glTexCoord2f(poseOffsetX + poseWidth, 0);
    glVertex2f(x + width, y + height);
    glTexCoord2f(poseOffsetX, 0);
    glVertex2f(x, y + height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Character::moveUp(float distance, const Map &map)
{
    float newY = y + distance;
    if (newY + height <= screenHeight && !isCollision(x, newY, map))
    {
        y = newY;
    }
    else
    {
        std::cout << "Warning: Collision detected moving up!" << std::endl;
    }
}

void Character::moveDown(float distance, const Map &map)
{
    float newY = y - distance;
    if (newY >= 0 && !isCollision(x, newY, map))
    {
        y = newY;
    }
    else
    {
        std::cout << "Warning: Collision detected moving down!" << std::endl;
    }
}

void Character::moveLeft(float distance, const Map &map)
{
    float newX = x - distance;
    if (newX >= 0 && !isCollision(newX, y, map))
    {
        x = newX;
    }
    else
    {
        std::cout << "Warning: Collision detected moving left!" << std::endl;
    }
}

void Character::moveRight(float distance, const Map &map)
{
    float newX = x + distance;
    if (newX + width <= screenWidth && !isCollision(newX, y, map))
    {
        x = newX;
    }
    else
    {
        std::cout << "Warning: Collision detected moving right!" << std::endl;
    }
}

bool Character::isCollision(float newX, float newY, const Map &map)
{
    // Check corners of the character's bounding box
    return map.checkCollisionWithMap(newX, newY) ||
           map.checkCollisionWithMap(newX + width, newY) ||
           map.checkCollisionWithMap(newX, newY + height) ||
           map.checkCollisionWithMap(newX + width, newY + height);
}
float Character::getScreenWidth()
{
    return screenWidth;
}

float Character::getScreenHeight()
{
    return screenHeight;
}

void Character::loseLife()
{
    lives--;
}

void Character::resetLives()
{
    lives = 3; // Defina MAX_LIVES conforme necessário
}
