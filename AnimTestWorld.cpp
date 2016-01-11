#include "AnimTestWorld.hpp"




SimpleBouncingBall::SimpleBouncingBall()
{
    timetick = 0;
    vel0  =  0.1;
    accel = -0.0005;
    y = 0;
}

void SimpleBouncingBall::draw()
{
    glColor3f(0.0f, 0.0f, 1.0f );
    glTranslatef(0.0f, y, 0.0f);
    glutSolidSphere(2.0,16,16);
}

void SimpleBouncingBall::updateFrame(int elapsedTime)
{
    timetick += elapsedTime;

    y = vel0*timetick + 0.5*accel*timetick*timetick;
    if (y < 0.0) {
        y = 0.0;
        timetick=0;
    }
};

AnimTestWorld::AnimTestWorld(WypWindow *parent) :
    parent(parent)
{
    spline = generateSpline(-25, 25, 150,
                           [](float z)->float { return sin(z/2.0) * 15; },
                           [](float x)->float { return cos(x/2.0) * 15; },
                           [](float y)->float { return y; });

    m = new Mesh("data/dark_fighter_6.obj");
    sa = new SplineAnimation(&spline, 10);

    m->setFlatColor({{.9, .3, .9}});
    m->setRotateZ(-90);
    m->addTransformation(sa->getTransformable());

    am = new AnimationMaster();
    am->addAnimatable(sa);
    am->addAnimatable(&simplebouncingball);
}

AnimTestWorld::~AnimTestWorld()
{
    delete am;
}

void AnimTestWorld::draw()
{
    am->update();

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
        simplebouncingball.draw();
    glPopMatrix();

    glPushMatrix();
        m->draw();
    glPopMatrix();
}
