/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

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
