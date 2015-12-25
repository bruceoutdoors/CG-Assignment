#pragma once

#include "../utilities/GlutWindow.hpp"
#include "MyAxis.hpp"
#include "MyVirtualWorld.hpp"

static GLfloat myblack[]   = { 0.0f, 0.0f, 0.0f, 1.0f };
static GLfloat mywhite[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
static GLfloat myred[]     = { 1.0f, 0.0f, 0.0f, 1.0f };
static GLfloat mygreen[]   = { 0.0f, 1.0f, 0.0f, 1.0f };
static GLfloat myblue[]    = { 0.0f, 0.0f, 1.0f, 1.0f };
static GLfloat mycyan[]    = { 0.0f, 1.0f, 1.0f, 1.0f };
static GLfloat mymagenta[] = { 1.0f, 0.0f, 1.0f, 1.0f };
static GLfloat myyellow[]  = { 1.0f, 1.0f, 0.0f, 1.0f };

static GLfloat mygray10Percent[] = { 0.1f, 0.1f, 0.1f, 1.0f };
static GLfloat mygray20Percent[] = { 0.2f, 0.2f, 0.2f, 1.0f };
static GLfloat mygray30Percent[] = { 0.3f, 0.3f, 0.3f, 1.0f };

struct MyWorld
{
    GLdouble rotateX, rotateY, rotateZ;
    GLdouble posX, posY, posZ;
    GLdouble scaleX, scaleY, scaleZ;
    void move(GLfloat xinc, GLfloat yinc, GLfloat zinc)
    {
        posX += xinc;
        posY += yinc;
        posZ += zinc;
    }
    void rotate(GLfloat xinc, GLfloat yinc, GLfloat zinc)
    {
        rotateX += xinc;
        rotateY += yinc;
        rotateZ += zinc;
    }
};

struct MyViewer
{
    GLdouble eyeX, eyeY, eyeZ;
    GLdouble centerX, centerY, centerZ;
    GLdouble upX, upY, upZ;

    GLdouble zNear, zFar;   // The distance to the near/far clipping plane
    GLdouble fieldOfView;   // Angle at Y direction
    GLdouble aspectRatio;   // width / height
};

struct MySetting
{
    GLdouble posInc;
    GLdouble angleInc;
    int mouseX, mouseY;
    bool mouseRightMode;
    bool mouseLeftMode;

    bool shadingMode;
};

class WypWindow : public GlutWindow
{
public:
    WypWindow(std::string title = "TCS2111 Computer Graphics");

    void draw() override;
    void onKeyboard(unsigned char key, int x, int y) override;
    void onSpecial(int key, int x, int y) override;
    void onMotion(int x, int y) override;
    void onMouse(int button, int state, int x, int y) override;

    void setVirtualWorld(MyVirtualWorld *vw);

private:
    void dataInit();
    void viewingInit();
    void lightingInit();
    void welcome();

    MyWorld    world;
    MyViewer   viewer;
    MySetting  setting;
    MyAxis     worldaxis;
    MyVirtualWorld *virtualworld;
};
