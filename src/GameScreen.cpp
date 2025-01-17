#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen() : background("./img/bg2.png") {

    // Load the map from a file
    map.loadMap("./src/Fase2.txt");
}

void GameScreen::render() {
    // Renderiza background
    glColor3f(1.0f, 1.0f, 1.0f); // Define a cor para branco para garantir que a textura seja renderizada com suas cores originais
    glEnable(GL_TEXTURE_2D);
    background.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(0, 0);
    glTexCoord2f(1, 1); glVertex2f(812, 0);
    glTexCoord2f(1, 0); glVertex2f(812, 588);
    glTexCoord2f(0, 0); glVertex2f(0, 588);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // // Render map over the background
    // for (int y = 0; y < map.getHeight(); ++y) {
    //     for (int x = 0; x < map.getWidth(); ++x) {
    //         if (map.getBlockType(x, y) == BlockType::SOLID) {
    //             // Render a solid block
    //             glColor3f(0.0f, 0.0f, 0.0f); // Set color to black for solid blocks
    //             glBegin(GL_QUADS);
    //             glVertex2f(x * 14, y * 14);
    //             glVertex2f((x + 1) * 14, y * 14);
    //             glVertex2f((x + 1) * 14, (y + 1) * 14);
    //             glVertex2f(x * 14, (y + 1) * 14);
    //             glEnd();
    //         }
    //     }
    // }
}
