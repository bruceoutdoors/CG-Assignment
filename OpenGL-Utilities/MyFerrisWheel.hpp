//
//  MyFerrisWheel.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef MyFerrisWheel_hpp
#define MyFerrisWheel_hpp

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include "utilities/Animatable.hpp"
#include "MySpotlight.hpp"
#include "Person.hpp"
#include <vector>
#include "utilities/VecMatMath.hpp"
class MyFerrisWheel : public Animatable
{
public:
    MyFerrisWheel(int rotatespeed = 90);
    ~MyFerrisWheel();
    void draw();
    void drawSeat(GLfloat angle_to_rotate, int current_index);
    void drawBar();
    void updateFrame(int elapseTime) override;
private:
    GLUquadricObj *pObj;

    std::vector<Person*> people;
    //    MySpotLights myspotlights;

    std::vector<vec3> colors= {
        {{1.0f, 1.0f, 0.0f}},
        {{0.0f, 1.0f, 0.0f}},
        {{0.0f, 0.0f, 1.0f}},
        {{1.0f, 1.0f, 0.0f}},
        {{0.0f, 1.0f, 1.0f}},
        {{1.0f, 0.0f, 1.0f}}
    };

    int rotatespeed;
    int rotateangle;
    int total_seats = 10;
};

#endif /* MyFerrisWheel_hpp */
