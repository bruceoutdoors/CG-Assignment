#pragma once

#include <array>
#include <GL/gl.h>

typedef std::array<float, 3> vec3;
typedef std::array<float, 2> vec2;

struct Viewer
{
    GLdouble eyeX, eyeY, eyeZ;
    GLdouble centerX, centerY, centerZ;
    GLdouble upX, upY, upZ;

    GLdouble zNear, zFar;   // The distance to the near/far clipping plane
    GLdouble fieldOfView;   // Angle at Y direction
    GLdouble aspectRatio;   // width / height
};

struct World
{
    GLdouble rotateX, rotateY, rotateZ;
    GLdouble posX, posY, posZ;
    GLdouble scaleX, scaleY, scaleZ;
    void move(GLfloat xinc, GLfloat yinc, GLfloat zinc)
    {
        posX += xinc;
        posY += yinc;
        posZ += zinc;
    }
    void rotate(GLfloat xinc, GLfloat yinc, GLfloat zinc)
    {
        rotateX += xinc;
        rotateY += yinc;
        rotateZ += zinc;
    }
};
