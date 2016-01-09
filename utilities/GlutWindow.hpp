#pragma once

#include <string>
#include <functional>
#include <GL/gl.h>

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

private:
    int id;
    GLint x, y;
    GLint width, height;
    std::string title;
};

