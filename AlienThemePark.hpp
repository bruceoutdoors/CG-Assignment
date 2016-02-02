#pragma once

#include "utilities/MyVirtualWorld.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/MyModelLoader.hpp"
#include "utilities/WypWindow.hpp"
#include "utilities/Animatable.hpp"
#include "utilities/AnimationMaster.hpp"
#include "utilities/Drawable.hpp"
#include "utilities/SplineAnimation.hpp"

#include "RollerCoaster.hpp"
#include "FerrisMonster.hpp"

#include <string>
#include <vector>

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif


using namespace std;

class AlienThemePark : public MyVirtualWorld
{
public:
    AlienThemePark();
    virtual ~AlienThemePark();
    void draw() override;

private:
    FerrisMonster ferrismonster;
    RollerCoaster rollercoaster;
    AnimationMaster am;
    Mesh spaceship;
    SplineAnimation *sa;
    vector<vec3> spline;
};
