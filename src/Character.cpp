#include "Character.h"
#include "Game.h"
#include <iostream>

Character::Character() : spriteSheet("./img/Goku2.png"), x(100.0f), y(85.0f), lives(3) {}

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
        facingRight = false;
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
        facingRight = true;
    }
    else
    {
        std::cout << "Warning: Collision detected moving right!" << std::endl;
    }
    if (isFoco(x, y, map)) {
            std::cerr << "Warning: Character stepped on a foco!\n";
        }
}

void Character::getPoints(const Map &map){
    if (isFoco(x, y, map)){
        points += 10;
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

bool Character::isFoco(float X, float Y, const Map &map)
{
    // Check corners of the character's bounding box
    return map.checkFocoWithMap(X, Y) ||
           map.checkFocoWithMap(X + width, Y) ||
           map.checkFocoWithMap(X, Y + height) ||
           map.checkFocoWithMap(X + width, Y + height);
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

void Character::resetPoints() {
    points = 0;
}

void Character::shoot() {
    projectiles.push_back(Projectile(x + 10, y + 10));
}

void Character::updateProjectiles() {
    for (auto& projectile : projectiles) {
        projectile.update();
    }

    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(), [](Projectile& p) { return p.isOffScreen(); }),
        projectiles.end()
    );
}

void Character::renderProjectiles() {
    for (auto& projectile : projectiles) {
        projectile.render();
    }
}

std::vector<Projectile>& Character::getProjectiles() {
    return projectiles;
}