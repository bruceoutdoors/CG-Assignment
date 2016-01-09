#include "utilities/WypWindow.hpp"
#include "AnimTestWorld.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    WypWindow w;
    AnimTestWorld vw(&w);
    w.setVirtualWorld(&vw);

    glutMainLoop();
}
