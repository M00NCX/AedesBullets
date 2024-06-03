#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/glew.h>
#include <iostream>

class Platform {
public:
    float x, y, width, height;
    GLuint textureID;

    Platform(float posX, float posY, float w, float h) : x(posX), y(posY), width(w), height(h), textureID(0) {}

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

    void render() {
        if (textureID == 0) return;

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(-width / 2.0f, -height / 2.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(width / 2.0f, -height / 2.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(width / 2.0f, height / 2.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(-width / 2.0f, height / 2.0f);
        glEnd();

        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
};

#endif // PLATFORM_H
