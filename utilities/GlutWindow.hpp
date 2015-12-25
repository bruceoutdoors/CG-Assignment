#pragma once

#include <string>

class GlutWindow
{
public:
    GlutWindow(std::string title);
    virtual ~GlutWindow();

    int getId() const;

    virtual void draw() {};
    virtual void onReshape(int width, int height) {}
    virtual void onKeyboard(unsigned char key, int x, int y) {}
    virtual void onSpecial(int key, int x, int y) {}
    virtual void onMotion(int x, int y) {}
    virtual void onMouse(int button, int state, int x, int y) {}

private:
    int id;
};

