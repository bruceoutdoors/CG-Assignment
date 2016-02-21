//
//  MySwingLights.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef MySwingLights_hpp
#define MySwingLights_hpp

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include "utilities/Animatable.hpp"
class MySwingLights : public Animatable
{
public:
    MySwingLights();
    ~MySwingLights();
    void setupLights();
    void toggleLight(int lightno);
    void draw();
    void updateFrame(int elapseTime); //elapsetime in milisec
private:
    GLUquadricObj *pObj;
    GLfloat length; //length of the pendulum
    GLfloat horizDisp1, horizDisp2; //horizontal displacement
    long int timestart;

    bool lighton[2]; //keep track if lights are on or off
};
#endif /* MySwingLights_hpp */
