#include "WypWindow.hpp"
#include "SelectMaster.hpp"
#include "Mesh.hpp"
#include <iostream>

WypWindow::WypWindow(std::string title) :
    GlutWindow(title),
    virtualworld(nullptr)
{
    dataInit();
    viewingInit();
    lightingInit();

    selMaster = new SelectMaster(viewer, world);

    welcome();
}

WypWindow::~WypWindow()
{
    delete selMaster;
}

void WypWindow::dataInit()
{
    world.rotateX  = 0.0;
    world.rotateY  = 0.0;
    world.rotateZ  = 0.0;
    world.posX     = 0.0;
    world.posY     = 0.0;
    world.posZ     = 0.0;
    world.scaleX   = 1.0;
    world.scaleY   = 1.0;
    world.scaleZ   = 1.0;

    viewer.eyeX    = 0.0;
    viewer.eyeY    = 0.0;
    viewer.eyeZ    = 40.0;
    viewer.centerX = 0.0;
    viewer.centerY = 0.0;
    viewer.centerZ = 0.0;
    viewer.upX     = 0.0;
    viewer.upY     = 1.0;
    viewer.upZ     = 0.0;
    viewer.zNear   = 0.1;
    viewer.zFar    = 500.0;
    viewer.fieldOfView = 60.0;
    viewer.aspectRatio = static_cast<GLdouble> (getWidth()) / getHeight();

    setting.posInc   = 1.0;
    setting.angleInc = 2.0;
    setting.mouseX   = 0;
    setting.mouseY   = 0;

    setting.mouseRightMode = false;
    setting.mouseLeftMode = false;

    setting.shadingMode = true;
}

void WypWindow::viewingInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(viewer.fieldOfView,
                   viewer.aspectRatio,
                   viewer.zNear,
                   viewer.zFar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer.eyeX,   viewer.eyeY,   viewer.eyeZ,
              viewer.centerX,viewer.centerY,viewer.centerZ,
              viewer.upX,    viewer.upY,    viewer.upZ );
}

void WypWindow::lightingInit()
{
    static GLfloat  ambient[] = { 0.0f,  0.0f,  0.0f, 1.0f };
    static GLfloat  diffuse[] = { 1.0f,  1.0f,  1.0f, 1.0f };
    static GLfloat specular[] = { 1.0f,  1.0f,  1.0f, 1.0f };
    static GLfloat  specref[] = { 1.0f,  1.0f,  1.0f, 1.0f };
    static GLfloat position[] = {10.0f, 10.0f, 10.0f, 1.0f };
    short shininess = 128;

    glDisable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, shininess);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
}


void WypWindow::draw()
{
    glTranslatef(world.posX, world.posY, world.posZ);
    glRotatef(world.rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(world.rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(world.rotateZ, 0.0f, 0.0f, 1.0f);
    glScalef(world.scaleX, world.scaleY, world.scaleZ);

    worldaxis.draw();

    if (virtualworld) {
        virtualworld->draw();
        virtualworld->calculateElapsedTime();
        virtualworld->tickTime();
    }
}

void WypWindow::onKeyboard(unsigned char key, int x, int y)
{
    GLfloat xinc,yinc,zinc;
    xinc = yinc = zinc = 0.0;
    switch (key)
    {
    case 'a': case 'A': xinc = -setting.posInc;  break;
    case 'd': case 'D': xinc =  setting.posInc;  break;
    case 'q': case 'Q': yinc = -setting.posInc;  break;
    case 'e': case 'E': yinc =  setting.posInc;  break;
    case 'w': case 'W': zinc = -setting.posInc;  break;
    case 's': case 'S': zinc =  setting.posInc;  break;

    case 27  : exit(1); break;
    }

    world.move(xinc, yinc, zinc);
}

void WypWindow::onSpecial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_DOWN  : world.rotateX -= setting.angleInc;  break;
    case GLUT_KEY_UP    : world.rotateX += setting.angleInc;  break;
    case GLUT_KEY_LEFT  : world.rotateY -= setting.angleInc;  break;
    case GLUT_KEY_RIGHT : world.rotateY += setting.angleInc;  break;
    case GLUT_KEY_HOME  : dataInit(); break;
    case GLUT_KEY_F1    : setting.shadingMode = !setting.shadingMode;
                          if (setting.shadingMode)
                            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                            else
                              glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                          break;
    case GLUT_KEY_F2    : worldaxis.toggle();
                          break;
    case GLUT_KEY_F3    : GLboolean lightingIsOn;
                          glGetBooleanv(GL_LIGHTING, &lightingIsOn);
                          if (lightingIsOn==GL_TRUE)
                             glDisable(GL_LIGHTING);
                             else  glEnable(GL_LIGHTING);
                          break;
    }
}

void WypWindow::onMotion(int x, int y)
{
    y = getHeight() - y;
    GLint xinc = x - setting.mouseX;
    GLint yinc = y - setting.mouseY;

    if(setting.mouseRightMode) {
        world.rotate(0.0f, 0.0f, -xinc*0.5);
    }

    if(setting.mouseLeftMode) {
        world.rotate(-yinc*0.5, xinc*0.5, 0.0f);
    }

    setting.mouseX = x;
    setting.mouseY = y;
    glutPostRedisplay();
}

void WypWindow::onMouse(int button, int state, int x, int y)
{
    y = getHeight() - y;
    switch (button) {
    case GLUT_RIGHT_BUTTON:
       if (state == GLUT_DOWN && !setting.mouseRightMode) {
          setting.mouseX = x;
          setting.mouseY = y;
          setting.mouseRightMode = true;
       }

       if (state == GLUT_UP && setting.mouseRightMode) {
          setting.mouseRightMode = false;
       }
       break;
    case GLUT_LEFT_BUTTON:
       if (state == GLUT_DOWN && !setting.mouseLeftMode) {
          setting.mouseX = x;
          setting.mouseY = y;
          setting.mouseLeftMode = true;

          Selectable *s = selMaster->getSelect(x, y);
          // selMaster->removeSelectable(s);
          if (s) {
            Mesh *m = dynamic_cast<Mesh*>(s);
            if (m) std::cout << m->getName() << std::endl;
          }
       }

       if (state == GLUT_UP &&  setting.mouseLeftMode) {
          setting.mouseLeftMode = false;
       }
       break;
    }
}

void WypWindow::welcome()
{
    std::cout
    << "*****************************************************************\n"
    << "*                   TCS2111 Computer Graphics                   *\n"
    << "*                     Trimester II, 2007/08                     *\n"
    << "*              Faculty of IT, Multimedia University             *\n"
    << "*    Copyright (C) 2007 by Ya-Ping Wong <ypwong@mmu.edu.my>     *\n"
    << "*****************************************************************\n"
    << "| Press:                                                        |\n"
    << "|   <a>,<d>,<w>,<s>,<q>,<e> => move world                       |\n"
    << "|   <arrows>                => rotate world                     |\n"
    << "|   HOME                    => restore defaults                 |\n"
    << "|   ESC                     => exit                             |\n"
    << "|                                                               |\n"
    << "|   F1                      => toggle shading / wire-frame mode |\n"
    << "|   F2                      => toggle rendering of axes         |\n"
    << "|   F3                      => toggle lighting on / off         |\n"
    << "|                                                               |\n"
    << "| Mouse (Left Drag or Right Drag) => rotate world               |\n"
    << "|                                                               |\n"
    << "*****************************************************************\n"
    << "|                      H A V E   F U N  !!!                     |\n"
    << "*****************************************************************\n";
}

void WypWindow::setVirtualWorld(MyVirtualWorld* vw)
{
    virtualworld = vw;
}

SelectMaster *WypWindow::getSelectMaster()
{
    return selMaster;
}


void WypWindow::onReshape(int width, int height)
{
    this->width = width;
    this->height = height;
    viewer.aspectRatio = static_cast<GLdouble> (width) / height;
    viewingInit();
}
