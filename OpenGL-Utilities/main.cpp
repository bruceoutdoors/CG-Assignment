/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

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
