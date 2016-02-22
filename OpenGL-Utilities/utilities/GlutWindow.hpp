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

#include <string>
#include <functional>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class GlutWindow
{
public:
    GlutWindow(std::string title);
    virtual ~GlutWindow();

    // events
    virtual void draw() {};
    virtual void onReshape(int width, int height) {}
    virtual void onKeyboard(unsigned char key, int x, int y) {}
    virtual void onSpecial(int key, int x, int y) {}
    virtual void onMotion(int x, int y) {}
    virtual void onMouse(int button, int state, int x, int y) {}

    void executeAsCurrentWindow(std::function<void()> func);

    // getter setters
    int   getId() const;
    GLint getX() const;
    void  setX(GLint x);
    GLint getY() const;
    void  setY(GLint x);
    GLint getWidth() const;
    void  setWidth(GLint width);
    GLint getHeight() const;
    void  setHeight(GLint height);
    std::string getTitle() const;
    void  setTitle(std::string title);

protected:
    int id;
    GLint x, y;
    GLint width, height;
    std::string title;
};

