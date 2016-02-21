//
//  MerryGoRound.cpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#include "MerryGoRound.hpp"
#include <random>



MyMerryGoRound::MyMerryGoRound(int rotatespeed):rotatespeed(rotatespeed) {
    //Setup Quadric Object
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    for(int i = 0 ; i < total_seats; i++ ) {
        Person* person = new Person();
        person->setScale(0.4);
        people.push_back(person);
    }
}
MyMerryGoRound::~MyMerryGoRound() {
    gluDeleteQuadric(pObj);
}
void MyMerryGoRound::draw()
{
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    
    drawBar();
    glPopMatrix();
//    srand(1); //initialize the random number generator
//    // fill up later
    glEnable(GL_CULL_FACE);
//    myspotlights.setupLights();
}
void MyMerryGoRound::drawSeat(GLfloat angle_to_rotate, int current_index)
{
//    myspotlights.draw();
    
    glPushMatrix();

    glRotatef(angle_to_rotate, 0, 1, 0);
    gluCylinder(pObj,0.5f, 0.5f, 20.0f, 30, 5);
    glTranslatef(0, 0, 20);
    glRotatef(90, 1, 0, 0);
    gluCylinder(pObj,0.5f, 0.5f, 20.0f, 30, 5);
    glTranslatef(0, 0, 20);
    glRotatef(90, 0, 1, 0);
    glColor3f(colors[current_index % colors.size()][0] ,
               colors[current_index % colors.size()][1],
               colors[current_index% colors.size()][2] );
    
    

    gluCylinder(pObj,1.0f, 3.0f, 5.0f, 30, 5);

    glRotatef(270, 0, 0, 1);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, -4);
    people[current_index]->draw();
    
    glPopMatrix();
    //color list, you may use a random number to pick the color
};
void MyMerryGoRound::drawBar()
{
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    gluCylinder(pObj,3.0f, 3.0f, 30.0f, 30, 5);
    glPopMatrix();
    
    glTranslatef(0, 30, 0);
    

    for(int i = 1 ; i < 10 ; i ++) {
        drawSeat( ( 360 *  i/total_seats) - rotateangle, i);
    }

    
    
    // fill up later
}

void MyMerryGoRound::updateFrame(int elapseTime) {
    rotateangle += elapseTime * rotatespeed / 1000.0;
    if (rotateangle>=360)
    {
        rotateangle = 360 - rotateangle;
    }
    
}