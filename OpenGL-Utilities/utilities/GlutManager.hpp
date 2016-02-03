#pragma once

#include <map>

class GlutWindow;

class GlutManager
{
public:
    static void addGlutWindow(int id, GlutWindow* gw);

    static void displayFunc();
    static void reshapeFunc(int width, int height);
    static void keyboardFunc(unsigned char key, int x, int y);
    static void specialFunc(int key, int x, int y);
    static void motionFunc(int x, int y);
    static void mouseFunc(int button, int state, int x, int y);

private:
    static void updateActiveGlutWindow();

    static std::map<int, GlutWindow*> idToWindow;
    static GlutWindow *activeGlutWindow;
};
