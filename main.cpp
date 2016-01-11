#include "utilities/WypWindow.hpp"
#include "AnimTestWorld.hpp"
#include <iostream>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#endif

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    WypWindow w;
    AnimTestWorld vw;
    w.setVirtualWorld(&vw);

    glutMainLoop();
}
