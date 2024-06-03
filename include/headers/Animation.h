#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <vector>

class Animation {
public:
    std::vector<GLuint> frames; // Vetor de IDs das texturas dos frames
    int currentFrame;
    float frameDuration;
    float elapsedTime;

    Animation() : currentFrame(0), frameDuration(0.1f), elapsedTime(0.0f) {}

    void addFrame(GLuint textureID) {
        frames.push_back(textureID);
    }

    void update(float deltaTime) {
        elapsedTime += deltaTime;
        if (elapsedTime >= frameDuration) {
            currentFrame = (currentFrame + 1) % frames.size();
            elapsedTime = 0.0f;
        }
    }

    GLuint getCurrentFrame() const {
        if (frames.empty()) return 0;
        return frames[currentFrame];
    }
};

#endif // ANIMATION_H
