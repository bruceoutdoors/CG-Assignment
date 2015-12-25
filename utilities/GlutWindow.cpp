#include "GlutWindow.hpp"
#include "GlutManager.hpp"
#include <GL/glut.h>

GlutWindow::GlutWindow(std::string title)
{
    glutInitWindowPosition(100, 100); // Set top-left position
    glutInitWindowSize(800, 500); //Set width and height

    id = glutCreateWindow(title.c_str());
    GlutManager::addGlutWindow(id, this);

    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutDisplayFunc(GlutManager::displayFunc);
    glutReshapeFunc(GlutManager::reshapeFunc);
    glutKeyboardFunc(GlutManager::keyboardFunc);
    glutSpecialFunc(GlutManager::specialFunc);
    glutMotionFunc(GlutManager::motionFunc);
    glutMouseFunc(GlutManager::mouseFunc);

    glPointSize(4.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glFrontFace(GL_CCW);
    glShadeModel (GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_CULL_FACE);
}


GlutWindow::~GlutWindow()
{
    //dtor
}

int GlutWindow::getId() const
{
    return id;
}
