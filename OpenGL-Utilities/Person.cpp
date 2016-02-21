//
//  Person.cpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#include "Person.hpp"
Person::Person(float scaleFactor):scaleFactor(scaleFactor) {
    //Setup Quadric Object
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    posx = 0.0f;
    posy = 0.0f;
    posz = 0.0f;
    roty = 30.0f;
    //initial velocity (in unit per second)
    velx = 40.0f;
    vely = 0.0f;
    velz = 3.0f;
}
Person::~Person() {
    gluDeleteQuadric(pObj);
}
void Person::drawBody() {
    
    //body
    glPushMatrix();
    glTranslatef(0, 4, 0);
    glRotatef(roty, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(pObj,3.0f, 3.0f, 6.0f, 5, 5);
    glPopMatrix();
    
    //hand-right
    glPushMatrix();
    glTranslatef(0, 10, 0);
    glRotatef(90, 0, 1, -0.5);
    gluCylinder(pObj,1.0f, 1.0f, 6.0f, 5, 5);
    glPopMatrix();
    
    //hand-left
    glPushMatrix();
    glTranslatef(0, 10, 0);
    glRotatef(90, 0, -1, 0.5);
    gluCylinder(pObj,1.0f, 1.0f, 6.0f, 5, 5);
    glPopMatrix();
    
    //leg-right
    glPushMatrix();
    glTranslatef(1, 6, 0);
    glRotatef(is_walking ? 45 + walkangle : 0, 0, 0, 0);
    gluCylinder(pObj,1.0f, 1.0f, 6.0f, 5, 5);
    glPopMatrix();
    
    //leg-left
    glPushMatrix();
    glTranslatef(-1, 6, 0);
    glRotatef(is_walking ? 135 - walkangle : 0, 0, 0, 0);
    gluCylinder(pObj,1.0f, 1.0f, 6.0f, 5, 5);
    glPopMatrix();
}
void Person::draw()
{
    glPushMatrix();
    glTranslatef(posx, posy, posz);
    glScalef(scaleFactor, scaleFactor,scaleFactor);
    drawBody();
    glTranslatef(0, 10, 0);
    drawHead();
    
    glPopMatrix();

}
void Person::drawHead() {

    glPushMatrix();
    //head
    glTranslatef(0.0f, 4.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    gluSphere(pObj,4.0f, 20, 20);
    //nose
    glTranslatef(0.0f, 0.0f, 4.0f); glColor3f(1.0f, 0.5f, 0.0f);
    gluCylinder(pObj,1.0f, 0.0f, 2.0f, 5, 5); //eyes
    glPushMatrix();
    glTranslatef(1.5f, 1.5f, -1.2f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj,1.0f, 10, 10);
    glTranslatef(0.0f, 0.2f, 0.5f);
    glColor3f(0.0f, 0.5f, 1.0f);
    gluSphere(pObj,0.7f, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5f, 1.5f, -1.2f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj,1.0f, 10, 10);
    glTranslatef(0.0f, 0.2f, 0.5f);
    glColor3f(0.0f, 0.5f, 1.0f);
    gluSphere(pObj,0.7f, 10, 10);
    glPopMatrix();
    //mouth
    GLboolean cullingIsOn;
    glGetBooleanv(GL_CULL_FACE, &cullingIsOn);
    glDisable(GL_CULL_FACE);
    glTranslatef(0.0f, -1.8f, -1.2f);
    glRotatef(-45, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluDisk(pObj,0.0f, 1.5f, 10, 10);
    if (cullingIsOn==GL_TRUE)
        glEnable(GL_CULL_FACE);
    glPopMatrix();
}

void Person::updateFrame(int elapseTime) {
    if(is_walking) {
        walkangle = ((int)(walkangle +  (elapseTime * velx / 1000.0)) * 2) % 90;
        posz += velz * elapseTime / 1000;
    }
}