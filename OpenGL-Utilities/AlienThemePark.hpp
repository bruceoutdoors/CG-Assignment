/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

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
#include "MerryGoRound.hpp"
#include "MyFerrisWheel.hpp"
#include "Person.hpp"
#include <string>
#include <vector>
#include "MySwingLights.hpp"

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
    MySpotLights spotlights;
    MyMerryGoRound merrygoround;
    MyFerrisWheel ferriswheel;
    MySwingLights swinglights;


    Person person;

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
