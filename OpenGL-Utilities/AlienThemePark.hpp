#pragma once

#include "utilities/MyVirtualWorld.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/MyModelLoader.hpp"
#include "utilities/WypWindow.hpp"
#include "utilities/Animatable.hpp"
#include "utilities/AnimationMaster.hpp"
#include "utilities/Drawable.hpp"
#include "utilities/SplineAnimation.hpp"
#include "utilities/FloatingAnimation.hpp"

#include "RollerCoaster.hpp"
#include "FerrisMonster.hpp"
#include "MySpotlight.hpp"

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
    AlienThemePark(WypWindow *wypwindow);
    void setupLights();
    void toggleLight(int lightno);
    virtual ~AlienThemePark();
    void draw() override;

private:
    FerrisMonster ferrismonster;
    RollerCoaster rollercoaster;
    MySpotLights *spotlights;
    AnimationMaster am;
    Mesh spaceship;
    Mesh spaceCruiser;
    Mesh elephant;
    SplineAnimation *sa;
    SplineAnimation *rollercoaster_animation;
    FloatingAnimation *fa;
    Mesh *activeSelect;
    vector<vec3> spline;
    vector<vec3> coaster_spline;
    bool lighton[7];
    
};
