/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

//
//  MerryGoRound.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef MerryGoRound_hpp
#define MerryGoRound_hpp

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
class MyMerryGoRound : public Animatable
{
public:
    MyMerryGoRound(int rotatespeed = 90);
    ~MyMerryGoRound();
    void draw();
    void drawSeat(GLfloat angle_to_rotate, int current_index);
    void drawBar();
    void updateFrame(int elapseTime) override;
private:
    GLUquadricObj *pObj;
    std::vector<Person*> people;
//    MySpotLights myspotlights;

    int rotatespeed;
    int rotateangle;
    int total_seats = 10;
    std::vector<vec3> colors= {
        {{1.0f, 1.0f, 0.0f}},
        {{0.0f, 1.0f, 0.0f}},
        {{0.0f, 0.0f, 1.0f}},
        {{1.0f, 1.0f, 0.0f}},
        {{0.0f, 1.0f, 1.0f}},
        {{1.0f, 0.0f, 1.0f}}
    };

};

#endif /* MerryGoRound_hpp */
