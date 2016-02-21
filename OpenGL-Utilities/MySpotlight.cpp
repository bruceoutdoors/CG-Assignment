//
//  MySpotlight.cpp
//  OpenGL-Utilities
//
//  Created by Yong Lian Hii on 21/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#include "MySpotlight.hpp"
#include "CGLabMain.hpp"


MySpotLights::MySpotLights()
{
    pObj = gluNewQuadric();
    rotateangle= 0.0f;
    rotatespeed = 360.0; //degree per sec
    gluQuadricNormals(pObj, GLU_SMOOTH);
}
MySpotLights::~MySpotLights()
{
}
void MySpotLights::setupLights()
{
    glLightfv(GL_LIGHT1, GL_AMBIENT, myred);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, myred);
    glLightfv(GL_LIGHT1, GL_SPECULAR, myred);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 35);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.04);
    
    glLightfv(GL_LIGHT2, GL_AMBIENT, mygreen);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, mygreen);
    glLightfv(GL_LIGHT2, GL_SPECULAR, mygreen);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 35);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.04);
    
    glLightfv(GL_LIGHT3, GL_AMBIENT, myblue);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, myblue);
    glLightfv(GL_LIGHT3, GL_SPECULAR, myblue);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 35);
    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.04);
    
    
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    
//    for (int i=0; i<3; ++i)
//        lighton[i] = true;
}
void MySpotLights::toggleLight(int lightno) {
    static GLenum tag[] = {GL_LIGHT1, GL_LIGHT2, GL_LIGHT3};
    lighton[lightno] = !lighton[lightno];
    if (lighton[lightno])
        glEnable( tag[lightno] );
    else
        glDisable( tag[lightno] );
    
    
}
void MySpotLights::draw()
{
    GLboolean cullingIsOn;
    glGetBooleanv(GL_CULL_FACE, &cullingIsOn);
    glDisable(GL_CULL_FACE);
    
    static GLfloat position[] = {0.0f, 0.0f, 0.0f, 1.0f };
    static GLfloat direction[] = {0.0f, 0.0f, 1.0f, 1.0f };
    
    GLfloat radius=9.0f;
    
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateangle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.5f, 0.3f);
    gluDisk(pObj,radius-1.0f, radius+1.0f, 20, 5);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.1f);
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    gluDisk(pObj,radius-1.0f, radius+1.0f, 20, 5);
    glPopMatrix();
    
    glTranslatef(radius, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluCylinder(pObj,1.0f, 2.0f, 3.0f, 30, 5);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
    
    GLfloat dx=radius*0.5; // = radius*cos(M_PI/3);
    GLfloat dy=radius*0.8660;// = radius*sin(M_PI/3);
    
    glTranslatef(-radius-dx, dy, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    gluCylinder(pObj,1.0f, 2.0f, 3.0f, 30, 5);
    glLightfv(GL_LIGHT2, GL_POSITION, position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction);
    
    glTranslatef(0.0f, -2*dy, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    gluCylinder(pObj,1.0f, 2.0f, 3.0f, 30, 5);
    glLightfv(GL_LIGHT3, GL_POSITION, position);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direction);
    
    glPopMatrix();
    if (cullingIsOn==GL_TRUE)
        glEnable(GL_CULL_FACE);
}
void MySpotLights::updateFrame(int elapseTime) //elapsetime in milisec
{
    rotateangle += elapseTime * rotatespeed / 1000.0;
    if (rotateangle>=360)
    {
        rotateangle = 360 - rotateangle;
    }
};
