#pragma once

#include "MiscStructs.hpp"
#include "GlutWindow.hpp"
#include "MyAxis.hpp"
#include "MyVirtualWorld.hpp"
#include "Signal.hpp"
#include "Selectable.hpp"
#include "SelectMaster.hpp"

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

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
    void onReshape(int width, int height) override;
    void onMouseWheel(int, int, int, int);

    Signal<unsigned char> *getOnKeyboardSignal();
    Signal<int> *getOnSpecialSignal();
    Signal<int, int> *getOnMotionSignal();
    Signal<int, int, int, int> *getOnMouseSignal();
    Signal<int, int> *getOnReshapeSignal();
    Signal<Selectable*> *getOnSelectSignal();

    void setVirtualWorld(MyVirtualWorld *vw);
    SelectMaster *getSelectMaster();

private:
    void dataInit();
    void viewingInit();
    void lightingInit();
    void welcome();

    Signal<unsigned char> onKeyboardSignal;
    Signal<int> onSpecialSignal;
    Signal<int, int> onMotionSignal;
    Signal<int, int, int, int> onMouseSignal;
    Signal<int, int> onReshapeSignal;
    Signal<Selectable*> onSelectSignal;

    World    world;
    Viewer   viewer;
    MySetting  setting;
    MyAxis     worldaxis;
    MyVirtualWorld *virtualworld;
    SelectMaster *selMaster;
};
