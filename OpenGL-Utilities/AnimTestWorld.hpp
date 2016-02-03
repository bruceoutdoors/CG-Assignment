#pragma once

#include "utilities/MyVirtualWorld.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/MyModelLoader.hpp"
#include "utilities/WypWindow.hpp"
#include "utilities/Animatable.hpp"
#include "utilities/AnimationMaster.hpp"
#include "utilities/Drawable.hpp"
#include "utilities/SplineAnimation.hpp"
#include <string>
#include <vector>

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

class SimpleBouncingBall : public Animatable, public Drawable
{
public:
    SimpleBouncingBall();
    void draw() override;
    void updateFrame(int elapsedTime) override;

private:
    long int timetick;
    float vel0;
    float accel;
    float y;
};

class AnimTestWorld : public MyVirtualWorld
{
public:
    AnimTestWorld();
    virtual ~AnimTestWorld();
    void draw() override;

private:
    SimpleBouncingBall simplebouncingball;
    AnimationMaster am;
    Mesh m;
    SplineAnimation *sa;
    vector<vec3> spline;
};
