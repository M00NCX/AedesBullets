#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/glew.h>
#include <iostream>

class Player {
public:
    float x, y; // Posição do personagem
    float velocityX, velocityY; // Velocidade do personagem
    GLuint textureID; // ID da textura

    Player() : x(0.0f), y(0.0f), velocityX(0.0f), velocityY(0.0f), textureID(0) {}

    bool loadTexture(const char* filePath) {
        SDL_Surface* surface = IMG_Load(filePath);
        if (!surface) {
            std::cerr << "Erro ao carregar a imagem: " << IMG_GetError() << std::endl;
            return false;
        }

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        int mode = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        SDL_FreeSurface(surface);

        return true;
    }

    void handleEvent(const SDL_Event& e) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    velocityX = -0.1f;
                    break;
                case SDLK_RIGHT:
                    velocityX = 0.1f;
                    break;
                case SDLK_UP:
                    velocityY = 0.1f;
                    break;
                case SDLK_DOWN:
                    velocityY = -0.1f;
                    break;
            }
        } else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    velocityX = 0.0f;
                    break;
                case SDLK_UP:
                case SDLK_DOWN:
                    velocityY = 0.0f;
                    break;
            }
        }
    }

    void update(float deltaTime) {
        x += velocityX * deltaTime;
        y += velocityY * deltaTime;
    }

    void render() {
        if (textureID == 0) return; // Certifique-se de que a textura foi carregada

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glBegin(GL_QUADS);
        // Coordenadas de textura ajustadas
        glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.1f, -0.1f);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(0.1f, -0.1f);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(0.1f, 0.1f);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.1f, 0.1f);
        glEnd();

        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
};

#endif // PLAYER_H
