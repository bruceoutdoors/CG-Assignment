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

