#include "MyAxis.hpp"

MyAxis::MyAxis()
{
    setXColor(1.0f, 0.0f, 0.0f);
    setYColor(0.0f, 1.0f, 0.0f);
    setZColor(0.0f, 0.0f, 1.0f);
    setLength(20.0f, 20.0f, 20.0f);
    setLineStipple(1, 0xffff);
    setLineWidth(1);
    shoulddraw = true;
}

void MyAxis::draw()
{
    if (!shoulddraw) return;

     GLboolean lightingIsOn;
     glGetBooleanv(GL_LIGHTING, &lightingIsOn);
     glDisable(GL_LIGHTING);

     GLint oldlinestipplerepeatfactor;
     GLint oldlinestipplepattern;
     GLfloat  oldlinewidth;
     GLboolean stippleIsOn;
     glGetIntegerv(GL_LINE_STIPPLE_REPEAT, &oldlinestipplerepeatfactor);
     glGetIntegerv(GL_LINE_STIPPLE_PATTERN, &oldlinestipplepattern);
     glGetFloatv(GL_LINE_WIDTH, &oldlinewidth);
     glGetBooleanv(GL_LINE_STIPPLE,&stippleIsOn);

     glEnable(GL_LINE_STIPPLE);
     glLineWidth(linewidth);
     glLineStipple(linestipplerepeatfactor, linestipplepattern);
     glBegin(GL_LINES);
        //x-axis
        glColor3f(xred, xgreen, xblue);

        glVertex3f( 0.0, 0.0, 0.0);
        glVertex3f(xlen, 0.0, 0.0);
        //x-axis arrow
        glVertex3f(    xlen, 0.0,  0.0);
        glVertex3f(0.9*xlen, 0.0,  0.05*xlen);
        glVertex3f(    xlen, 0.0,  0.0);
        glVertex3f(0.9*xlen, 0.0, -0.05*xlen);

        //y-axis
        glColor3f(yred, ygreen, yblue);
        glVertex3f(0.0,  0.0, 0.0);
        glVertex3f(0.0, ylen, 0.0);
        //y-axis arrow
        glVertex3f(       0.0,     ylen, 0.0);
        glVertex3f( 0.05*ylen, 0.9*ylen, 0.0);
        glVertex3f(       0.0,     ylen, 0.0);
        glVertex3f(-0.05*ylen, 0.9*ylen, 0.0);

        //z-axis
        glColor3f(zred, zgreen, zblue);
        glVertex3f(0.0, 0.0,  0.0);
        glVertex3f(0.0, 0.0, zlen);
        //z-axis arrow
        glVertex3f(0.0, 0.0, zlen);
        glVertex3f( 0.05*zlen, 0.0, 0.9*zlen);
        glVertex3f(       0.0, 0.0,     zlen);
        glVertex3f(-0.05*zlen, 0.0, 0.9*zlen);
     glEnd();

     glLineWidth(oldlinewidth);
     glLineStipple(oldlinestipplerepeatfactor, oldlinestipplepattern);

     if (stippleIsOn==GL_FALSE)
        glDisable(GL_LINE_STIPPLE);

     if (lightingIsOn==GL_TRUE)
        glEnable(GL_LIGHTING);
}


