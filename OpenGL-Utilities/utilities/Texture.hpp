#ifndef TEXTURE_H
#define TEXTURE_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <string>

class ShaderMan;

class Texture
{
public:
    Texture(const std::string &path);
    virtual ~Texture();
    void use();

private:
    GLuint textureID;
};

#endif // TEXTURE_H
