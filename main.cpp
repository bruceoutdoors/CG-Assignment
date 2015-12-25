#include "wyp/WypWindow.hpp"
#include "CGLab01VirtualWorld.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    WypWindow w;
    CGLab01VirtualWorld vw;
    w.setVirtualWorld(&vw);

    glutMainLoop();
}
