#include "utilities/GlutWindow.hpp"
#include <iostream>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#endif

using namespace std;

class MyWindow : public GlutWindow
{
public:
    MyWindow(string title) : GlutWindow(title) {}
    void onKeyboard(unsigned char key, int x, int y) override {
        if (key == 'a') {
            cout << "B";
        }
    }
};

class OtherWindow : public GlutWindow
{
public:
    OtherWindow(string title) : GlutWindow(title) {}

    void onKeyboard(unsigned char key, int x, int y) override {
        if (key == 'a') {
            cout << "A";
        }
    }
};

//int main(int argc, char **argv)
//{
//    glutInit(&argc, argv);
//
//    MyWindow w("test window");
//    OtherWindow w2("test window 2");
//    w.setX(550);
//    w2.setWidth(400);
//    w2.setHeight(600);
//    w.setTitle("MACIBAI");
//
//    glutMainLoop();
//}
