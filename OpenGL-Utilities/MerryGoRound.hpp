//
//  MerryGoRound.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef MerryGoRound_hpp
#define MerryGoRound_hpp

#include <GLUT/glut.h>
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
        {1.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 1.0f},
        {1.0f, 0.0f, 1.0f}
    };

};

#endif /* MerryGoRound_hpp */
