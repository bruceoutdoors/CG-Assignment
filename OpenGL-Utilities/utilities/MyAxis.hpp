/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#ifndef MYAXIS_H
#define MYAXIS_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class MyAxis
{
 private:
    GLfloat xlen, ylen, zlen;
    GLfloat xred, xgreen, xblue;
    GLfloat yred, ygreen, yblue;
    GLfloat zred, zgreen, zblue;
    GLint    linestipplerepeatfactor;
    GLfloat  linewidth;
    GLushort linestipplepattern;
    bool     shoulddraw;
 public:
    MyAxis();
    void draw();

    void toggle()  { shoulddraw = !shoulddraw; }
    void enable()  { shoulddraw = true; }
    void disable() { shoulddraw = false; }

    void setLength(GLfloat xLen, GLfloat yLen, GLfloat zLen)
       { xlen = xLen; ylen = yLen; zlen = zLen; }
    void setXColor(GLfloat r, GLfloat g, GLfloat b)
       { xred = r; xgreen = g; xblue = b; }
    void setYColor(GLfloat r, GLfloat g, GLfloat b)
       { yred = r; ygreen = g; yblue = b; }
    void setZColor(GLfloat r, GLfloat g, GLfloat b)
       { zred = r; zgreen = g; zblue = b; }
    void setLineWidth(GLfloat lineWidth)
       { linewidth = lineWidth; }
    void setLineStipple(GLint repeatfactor, GLushort pattern)
       { linestipplerepeatfactor = repeatfactor, linestipplepattern = pattern; }
};

#endif // MYAXIS_H
