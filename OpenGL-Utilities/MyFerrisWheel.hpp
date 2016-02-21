//
//  MyFerrisWheel.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef MyFerrisWheel_hpp
#define MyFerrisWheel_hpp

#include <GLUT/glut.h>
#include "utilities/Animatable.hpp"
#include "MySpotlight.hpp"
class MyFerrisWheel : public Animatable
{
public:
    MyFerrisWheel(int rotatespeed = 90);
    ~MyFerrisWheel();
    void draw();
    void drawSeat(GLfloat angle_to_rotate);
    void drawBar();
    void updateFrame(int elapseTime) override;
private:
    GLUquadricObj *pObj;
    //    MySpotLights myspotlights;
    
    int rotatespeed;
    int rotateangle;
};

#endif /* MyFerrisWheel_hpp */
