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
//  Person.hpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
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
