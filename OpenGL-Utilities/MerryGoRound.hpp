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
class MyMerryGoRound : public Animatable
{
public:
    MyMerryGoRound(int rotatespeed = 90);
    ~MyMerryGoRound();
    void draw();
    void drawSeat(GLfloat angle_to_rotate);
    void drawBar();
    void updateFrame(int elapseTime) override;
private:
    GLUquadricObj *pObj;
    int rotatespeed;
    int rotateangle;
};

#endif /* MerryGoRound_hpp */
