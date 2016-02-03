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

    static Selectable* getSelectable(const GLuint id);

private:
    GLuint id;

    static GLuint currentId;
    static std::map<GLuint, Selectable*> idToSelectable;
};
