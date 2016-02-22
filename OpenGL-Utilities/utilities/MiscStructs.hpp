/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#pragma once

#include <array>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

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
