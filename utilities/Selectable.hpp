#pragma once

#include <GL/gl.h>
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
