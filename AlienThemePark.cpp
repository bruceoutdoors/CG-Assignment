#include "AlienThemePark.hpp"

AlienThemePark::AlienThemePark()
{

}

AlienThemePark::~AlienThemePark()
{

}

void AlienThemePark::draw()
{
    ferrismonster.draw();

    glColor3f(0.5, 0.6, .8);
    glBegin(GL_QUADS);
        glVertex3f(-50, 0, -50);
        glVertex3f(-50, 0, 50);
        glVertex3f(50, 0, 50);
        glVertex3f(50, 0, -50);
    glEnd();
}
