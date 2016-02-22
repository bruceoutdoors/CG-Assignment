/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "MyVirtualWorld.hpp"
#include "AnimationMaster.hpp"
#include "WypWindow.hpp"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

MyVirtualWorld::MyVirtualWorld(WypWindow *wypwindow) :
    wypwindow(wypwindow)
{
    wypwindow->setVirtualWorld(this);

}

MyVirtualWorld::~MyVirtualWorld()
{
}

