#pragma once

#include "Typedefs.hpp"
#include <vector>
#include <GL/gl.h>

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
