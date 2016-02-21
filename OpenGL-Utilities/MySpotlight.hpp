//
//  MySpotlight.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef MySpotlight_hpp
#define MySpotlight_hpp

#include <stdio.h>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include "utilities/Animatable.hpp"
class MySpotLights : public Animatable
{
public:
    MySpotLights();
    ~MySpotLights();
    void setupLights();
    void toggleLight(int lightno);
    void draw();
    void updateFrame(int elapseTime) override;  //elapsetime in milisec
private:
    GLUquadricObj *pObj;
    GLfloat rotateangle, rotatespeed;
    bool lighton[3]; //keep track if lights are on or off
};

#endif /* MySpotlight_hpp */
