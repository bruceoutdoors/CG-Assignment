#include "utilities/WypWindow.hpp"
#include "AlienThemePark.hpp"
#include <iostream>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    WypWindow w;
    AlienThemePark vw(&w);

    glutMainLoop();
}
