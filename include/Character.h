#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/gl.h>
#include "Texture.h"
#include "Map.h"

class Character {
public:
    // Constructor to initialize the character
    Character();

    // Method to render the character with a specific pose
    void render(int pose);

    // Methods to move the character
    void moveUp(float distance, const Map& map);
    void moveDown(float distance, const Map& map);
    void moveLeft(float distance, const Map& map);
    void moveRight(float distance, const Map& map);

private:
    // Sprite sheet texture for the character
    Texture spriteSheet;

    // Character position
    float x, y;

    // Character dimensions (adjust as needed)
    static constexpr float width = 35.0f;
    static constexpr float height = 40.0f;

    // Screen dimensions (adjust as needed)
    static constexpr float screenWidth = 800.0f;
    static constexpr float screenHeight = 600.0f;

    // Helper function to check collision with the map
    bool isCollision(float newX, float newY, const Map& map);
};

#endif // CHARACTER_H