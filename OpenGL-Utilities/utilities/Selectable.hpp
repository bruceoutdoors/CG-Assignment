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

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <map>
#include "Drawable.hpp"

class Selectable : public Drawable
{
public:
    Selectable();

    GLuint getId() const;

    virtual void drawSelector();
    virtual void drawHighlight() {}

    static Selectable* getSelectable(const GLuint id);

private:
    GLuint id;

    static GLuint currentId;
    static std::map<GLuint, Selectable*> idToSelectable;
};
