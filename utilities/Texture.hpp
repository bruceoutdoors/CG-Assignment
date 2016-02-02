#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>
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
