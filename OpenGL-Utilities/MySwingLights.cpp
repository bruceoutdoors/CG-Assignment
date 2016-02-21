//
//  MySwingLights.cpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#include "MySwingLights.hpp"
#include "CGLabMain.hpp"
MySwingLights::MySwingLights()
{
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    length = 25; //length of the pendulum
    timestart = glutGet(GLUT_ELAPSED_TIME); }
MySwingLights::~MySwingLights() {
}
void MySwingLights::setupLights() {
    glLightfv(GL_LIGHT4, GL_AMBIENT, mywhite);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, mywhite);
    glLightfv(GL_LIGHT4, GL_SPECULAR, mywhite);
    glLightf (GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
    
    glLightf (GL_LIGHT4,
              GL_LINEAR_ATTENUATION, 0.2);
    glLightfv(GL_LIGHT5, GL_AMBIENT, mywhite);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, mywhite);
    glLightfv(GL_LIGHT5, GL_SPECULAR, mywhite);
    glLightf (GL_LIGHT5, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf (GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.2);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);
    for (int i=0; i<2; ++i)
        lighton[i] = true;
}
void MySwingLights::toggleLight(int lightno) {
    static GLenum tag[] = {GL_LIGHT4, GL_LIGHT5};
    lighton[lightno] = !lighton[lightno];
    if (lighton[lightno])
        glEnable( tag[lightno] );
    else
        glDisable( tag[lightno] );
    
}
void MySwingLights::draw()
{
    static GLfloat position[] = {0.0f, 0.0f, 0.0f, 1.0f };
    float degreePerRad = 180/M_PI;
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -20.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(asin(horizDisp1/length)*degreePerRad, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluCylinder(pObj, 0.1f, 0.1f, length, 10, 10);
    glTranslatef(0.0f, 0.0f, length);
    gluSphere(pObj, 0.5, 10, 10);
    glLightfv(GL_LIGHT4, GL_POSITION, position);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 20.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(asin(horizDisp2/length)*degreePerRad, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluCylinder(pObj, 0.1f, 0.1f, length, 10, 10);
    glLightfv(GL_LIGHT5, GL_POSITION, position);
    glTranslatef(0.0f, 0.0f, length); gluSphere(pObj, 0.5, 10, 10);
    glPopMatrix();
}
void MySwingLights::updateFrame( int elapseTime) //elapsetime in milisec
{
    // the time since the pendulum starts.
    // This is another way to do timing for animation
    float currentTime = timestart - glutGet(GLUT_ELAPSED_TIME);
    float currentTimeInSec = currentTime / 1000.0;
    float D = 25; //D is max horizontal displacement
    float g= 50.0; //gravity, bigger value to swing faster
    float freq = sqrt( g/length ); //frequency of pendulum
    float k = freq * currentTimeInSec;
    //This equation is meant for pendulum of small angle //we use this as approximation though our angle is big
    horizDisp1 = D*sin( k - M_PI );
    horizDisp2 = D*sin( k );
};