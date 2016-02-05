#include "AlienThemePark.hpp"
#include <iostream>

using namespace std;

AlienThemePark::AlienThemePark(WypWindow *wypwindow) :
    MyVirtualWorld(wypwindow),
    spaceship("data/dark_fighter_6.obj"),
    spaceCruiser("data/space_cruiser_4.obj")
{
    spline = generateSpline(-25, 10, 150,
                            [](float z)->float { return sin(z/2.0) * 15; },
                            [](float x)->float { return cos(x/2.0) * 15; },
                            [](float y)->float { return y + 20; });

    sa = new SplineAnimation(&spline, 10);
    fa = new FloatingAnimation(1.2, .6);

    spaceship.setFlatColor({{.9, .3, .9}});
    spaceship.disableFlatColor();
    spaceship.setRotateZ(-90);
    spaceship.addTransformation(sa->getTransformable());
    spaceship.setTexture("data/dark_fighter_6_color.png");

    spaceCruiser.setTexture("data/space_cruiser_4_color.png");
    spaceCruiser.disableFlatColor();
    spaceCruiser.addTransformation(fa->getTransformable());
    spaceCruiser.setScale(.5);
    spaceCruiser.setTranslateZ(25);
    spaceCruiser.setTranslateY(10);

    am.addAnimatable(sa);
    am.addAnimatable(fa);

    wypwindow->getOnKeyboardSignal()->connect([&](unsigned char c)
    {
        cout << c;
    });

    wypwindow->getOnMouseSignal()->connect(
        [&](int button, int state, int x, int y)
    {
        if (state == GLUT_UP) {
            cout << "click: " << x << " " << y << endl;
        }
    });
}

AlienThemePark::~AlienThemePark()
{
    delete sa;
    delete fa;
}

void AlienThemePark::draw()
{
    am.update();

    glPushMatrix();

    GLboolean lightingIsOn;
    glGetBooleanv(GL_LIGHTING, &lightingIsOn);
    glDisable(GL_LIGHTING);

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < spline.size()-1; i++) {
        glVertex3fv(&spline[i][0]);
        glVertex3fv(&spline[i+1][0]);
    }
    glEnd();

    if (lightingIsOn) glEnable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
        spaceship.draw();
        spaceCruiser.draw();
    glPopMatrix();

    ferrismonster.draw();
    rollercoaster.draw();

    glColor3f(0.5, 0.6, .8);
    glBegin(GL_QUADS);
    glVertex3f(-50, 0, -50);
    glVertex3f(-50, 0, 50);
    glVertex3f(50, 0, 50);
    glVertex3f(50, 0, -50);
    glEnd();
}
