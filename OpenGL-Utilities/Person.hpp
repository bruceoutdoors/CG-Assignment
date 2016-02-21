//
//  Person.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include <GLUT/glut.h>
#include "utilities/Animatable.hpp"
class Person : public Animatable
{
public:
    Person();
    ~Person();
    void draw();
    void drawHead();
    void drawBody();
    void drawHands();
    void updateFrame(int elapseTime);
private:
    GLUquadricObj *pObj;
    GLfloat posx, posy, posz;
    GLfloat roty;
    int walkangle;
    float height = 5;
    GLfloat velx, vely, velz; //unit per sec
};

#endif /* Person_hpp */
