#include "AnimTestWorld.hpp"
#include "utilities/AnimationMaster.hpp"
#include "utilities/SelectMaster.hpp"
#include <GL/glut.h>

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
    am = new AnimationMaster();
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
        simplebouncingball.draw();
    glPopMatrix();
}
