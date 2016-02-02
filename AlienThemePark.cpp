#include "AlienThemePark.hpp"

AlienThemePark::AlienThemePark() : spaceship("data/dark_fighter_6.obj")
{
    spline = generateSpline(-25, 10, 150,
                            [](float z)->float { return sin(z/2.0) * 15; },
                            [](float x)->float { return cos(x/2.0) * 15; },
                            [](float y)->float { return y + 20; });

    sa = new SplineAnimation(&spline, 10);

    spaceship.setFlatColor({{.9, .3, .9}});
    spaceship.disableFlatColor();
    spaceship.setRotateZ(-90);
    spaceship.addTransformation(sa->getTransformable());
    spaceship.setTexture("data/dark_fighter_6_color.png");

    am.addAnimatable(sa);
}

AlienThemePark::~AlienThemePark()
{

}

void AlienThemePark::draw()
{
    am.update();

    glPushMatrix();
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < spline.size()-1; i++) {
        glVertex3fv(&spline[i][0]);
        glVertex3fv(&spline[i+1][0]);
    }
    glEnd();
    glEnable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
        spaceship.draw();
    glPopMatrix();

    ferrismonster.draw();

    glColor3f(0.5, 0.6, .8);
    glBegin(GL_QUADS);
    glVertex3f(-50, 0, -50);
    glVertex3f(-50, 0, 50);
    glVertex3f(50, 0, 50);
    glVertex3f(50, 0, -50);
    glEnd();
}
