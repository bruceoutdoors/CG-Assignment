#include "utilities/GlutWindow.hpp"
#include <iostream>
#include <GL/glut.h>

using namespace std;

class MyWindow : public GlutWindow
{
public:
    MyWindow(string title) : GlutWindow(title) {}

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

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    MyWindow w("test window");
    OtherWindow w2("test window 2");

    glutMainLoop();
}
