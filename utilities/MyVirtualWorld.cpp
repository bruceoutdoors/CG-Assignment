#include "MyVirtualWorld.hpp"
#include <GL/glut.h>

MyVirtualWorld::MyVirtualWorld()
{
    glEnable(GL_LIGHTING);
    timeold = std::chrono::high_resolution_clock::now();
}

MyVirtualWorld::~MyVirtualWorld()
{

}

void MyVirtualWorld::calculateElapsedTime()
{
    timenew    = std::chrono::high_resolution_clock::now();
    elapseTime = std::chrono::duration_cast<std::chrono::milliseconds>(timenew - timeold).count();
    timeold    = timenew;
}

