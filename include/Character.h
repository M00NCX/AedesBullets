#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/gl.h>
#include "Texture.h"
#include "Map.h"
#include "Projectile.h"
#include <vector>

class Character
{
public:
    // Constructor to initialize the character
    Character();

    // Method to render the character with a specific pose
    void render(int pose);

    // Methods to move the character
    void moveUp(float distance, const Map &map);
    void moveDown(float distance, const Map &map);
    void moveLeft(float distance, const Map &map);
    void moveRight(float distance, const Map &map);
    bool checkCollision(float otherX, float otherY, float otherWidth, float otherHeight);
    void loseLife();

    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    int getLives() const { return lives; }
    void getPoints(Map &map);
    int showPoints() const { return points; }
    bool isFoco(float X, float Y, const Map &map);

    // Métodos estáticos para obter screenWidth e screenHeight
    static float getScreenWidth();
    static float getScreenHeight();
    void resetLives(); // Método para reiniciar as vidas do 
    void resetPoints();

    void shoot(); // Método para lançar um projétil
    void updateProjectiles(); // Atualiza a posição dos projéteis
    void renderProjectiles(); // Renderiza os projéteis
    std::vector<Projectile>& getProjectiles(); // Retorna a lista de projéteis // Para obter os projéteis do personagem

private:
    // Sprite sheet texture for the character
    Texture spriteSheet;

    // Character position
    float x, y;

    // Character dimensions (adjust as needed)
    static constexpr float width = 25.0f;
    static constexpr float height = 30.0f;

    // Screen dimensions (adjust as needed)
    static constexpr float screenWidth = 812.0f;
    static constexpr float screenHeight = 588.0f;

    // Helper function to check collision with the map
    bool isCollision(float newX, float newY, const Map &map);
    int lives;
    int points;

    std::vector<Projectile> projectiles; // Vetor de projéteis
    bool facingRight; // Nova variável para direção do personagem
};

#endif // CHARACTER_H