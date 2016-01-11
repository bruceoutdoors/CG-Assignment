#include "GlutWindow.hpp"
#include "GlutManager.hpp"
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

GlutWindow::GlutWindow(std::string title) :
    x(100), y(100),
    width(800), height(500)
{
    glutInitWindowPosition(x, y); // Set top-left position
    glutInitWindowSize(width, height); //Set width and height

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

GLint GlutWindow::getX() const
{
    return x;
}

void GlutWindow::setX(GLint x)
{
    this->x = x;
    executeAsCurrentWindow([&](){ glutPositionWindow(x, y); });
}

GLint GlutWindow::getY() const
{
    return y;
}

void GlutWindow::setY(GLint x)
{
    this->y = y;
    executeAsCurrentWindow([&](){ glutPositionWindow(x, y); });
}

GLint GlutWindow::getWidth() const
{
    return width;
}

void GlutWindow::setWidth(GLint width)
{
    this->width = width;
    executeAsCurrentWindow([&](){ glutReshapeWindow(width, height); });
}

GLint GlutWindow::getHeight() const
{
    return height;
}

void GlutWindow::setHeight(GLint height)
{
    this->height = height;
    executeAsCurrentWindow([&](){ glutReshapeWindow(width, height); });
}

void GlutWindow::executeAsCurrentWindow(std::function<void()> func)
{
    int current = glutGetWindow();
    glutSetWindow(id);
    func();
    glutSetWindow(current);
}

std::string GlutWindow::getTitle() const
{
    return title;
}

void GlutWindow::setTitle(std::string title)
{
    this->title = title;
    executeAsCurrentWindow([&](){ glutSetWindowTitle(title.c_str()); });
}
