#pragma once

#include "MiscStructs.hpp"
#include "GlutWindow.hpp"
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

struct MySetting
{
    GLdouble posInc;
    GLdouble angleInc;
    int mouseX, mouseY;
    bool mouseRightMode;
    bool mouseLeftMode;

    bool shadingMode;
};

class SelectMaster;

class WypWindow : public GlutWindow
{
public:
    WypWindow(std::string title = "TCS2111 Computer Graphics");
    virtual ~WypWindow();

    void draw() override;
    void onKeyboard(unsigned char key, int x, int y) override;
    void onSpecial(int key, int x, int y) override;
    void onMotion(int x, int y) override;
    void onMouse(int button, int state, int x, int y) override;

    void setVirtualWorld(MyVirtualWorld *vw);
    SelectMaster *getSelectMaster();

private:
    void dataInit();
    void viewingInit();
    void lightingInit();
    void welcome();

    World    world;
    Viewer   viewer;
    MySetting  setting;
    MyAxis     worldaxis;
    MyVirtualWorld *virtualworld;
    SelectMaster *selMaster;
};
