#include "GlutManager.hpp"
#include "GlutWindow.hpp"
#include <GL/glut.h>

GlutWindow *GlutManager::activeGlutWindow = nullptr;
std::map<int, GlutWindow*> GlutManager::idToWindow;

void GlutManager::addGlutWindow(int id, GlutWindow* gw)
{
    idToWindow[id] = gw;
}

void GlutManager::displayFunc()
{
    updateActiveGlutWindow();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    activeGlutWindow->draw();
    glPopMatrix();

    glFlush();   // send any buffered output to be rendered
    glutSwapBuffers();

    glutPostRedisplay();
}

void GlutManager::reshapeFunc(int width, int height)
{
    updateActiveGlutWindow();
    activeGlutWindow->onReshape(width, height);
    glViewport(0, 0, width, height);
}

void GlutManager::keyboardFunc(unsigned char key, int x, int y)
{
    updateActiveGlutWindow();
    activeGlutWindow->onKeyboard(key, x, y);
}

void GlutManager::specialFunc(int key, int x, int y)
{
    updateActiveGlutWindow();
    activeGlutWindow->onSpecial(key, x, y);
}

void GlutManager::motionFunc(int x, int y)
{
    updateActiveGlutWindow();
    activeGlutWindow->onMotion(x, y);
}

void GlutManager::mouseFunc(int button, int state, int x, int y)
{
    updateActiveGlutWindow();
    activeGlutWindow->onMouse(button, state, x, y);
}

void GlutManager::updateActiveGlutWindow()
{
    activeGlutWindow = idToWindow[glutGetWindow()];
}

