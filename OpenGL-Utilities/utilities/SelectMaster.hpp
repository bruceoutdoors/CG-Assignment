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

#include "MiscStructs.hpp"
#include <vector>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Selectable;

class SelectMaster
{
public:
    SelectMaster(Viewer &v, World &w);
    Selectable *getSelect(int x, int y);
    void addSelectable(Selectable *s);
    void removeSelectable(Selectable *s);
    void clearSelectables();

private:
    Selectable *processHits(GLint hits, GLuint buffer[]);
    void restoreView();

    std::vector<Selectable*> selectables;
    Viewer &viewer;
    World &world;
};
