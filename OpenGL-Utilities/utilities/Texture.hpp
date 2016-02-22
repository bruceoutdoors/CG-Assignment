/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

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
