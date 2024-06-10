#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>
#include <string>

class Texture {
public:
    GLuint id;
    int width, height;

    Texture(const std::string& filename);
    void bind();
};

#endif // TEXTURE_H
