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
    Person(float scaleFactor = 1);
    ~Person();
    void draw();
    void drawHead();
    void drawBody();
    void drawHands();
    void setScale(float scale) { scaleFactor = scale; };
    void toggleWalking() { is_walking = !is_walking; };
    void updateFrame(int elapseTime);
private:
    GLUquadricObj *pObj;
    GLfloat posx, posy, posz;
    GLfloat roty;
    int walkangle = 0;
    float scaleFactor;
    GLfloat velx, vely, velz; //unit per sec
    bool is_walking = false;
};

#endif /* Person_hpp */
