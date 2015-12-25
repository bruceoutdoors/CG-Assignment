#include "CGLab01VirtualWorld.hpp"
#include <GL/glut.h>

CGLab01VirtualWorld::CGLab01VirtualWorld()
{
    mymodelloader.load("data/model_lowpolygonstanforddragon.txt",100);
    deer = new Mesh("data/deer.obj");
    deer->setFlatColor({{.9, .3, .9}});
    deer->setTranslateX(10.5f);
    deer->setTranslateZ(-7.0f);
    deer->setRotateY(15.0f);
    deer->setScale(0.5f);

    elephant = new Mesh("data/elephant-triangulated.obj");
    elephant->setFlatColor({{ .8, .1, .15 }});
    elephant->setTranslateX(-10.5f);
    elephant->setRotateY(-45.0f);
}

CGLab01VirtualWorld::~CGLab01VirtualWorld()
{
    delete deer;
    delete elephant;
}

void CGLab01VirtualWorld::tickTime()
{
    simplebouncingball.tickTime(elapseTime);
}

void SimplePolygon::draw()
{
    glDisable(GL_CULL_FACE);

    glBegin(GL_QUADS);
        //bottom
        glColor3f ( 1.0f,  0.0f,  0.0f );
        //glNormal3f( 0.0f, -1.0f,  0.0f );
        glVertex3f( 2.0f, -5.0f, -5.0f );
        glVertex3f( 2.0f, -5.0f,  5.0f );
        glVertex3f(-2.0f, -5.0f,  5.0f );
        glVertex3f(-2.0f, -5.0f, -5.0f );
        //right
        glColor3f ( 0.0f,  1.0f,  0.0f );
        //glNormal3f(0.96f,-0.29f,  0.0f );
        glVertex3f( 5.0f,  5.0f, -2.0f );
        glVertex3f( 5.0f,  5.0f,  2.0f );
        glVertex3f( 2.0f, -5.0f,  5.0f );
        glVertex3f( 2.0f, -5.0f, -5.0f );
        //top
        glColor3f ( 0.0f,  0.0f,  1.0f );
        //glNormal3f( 0.0f,  1.0f,  0.0f );
        glVertex3f(-5.0f,  5.0f, -2.0f );
        glVertex3f(-5.0f,  5.0f,  2.0f );
        glVertex3f( 5.0f,  5.0f,  2.0f );
        glVertex3f( 5.0f,  5.0f, -2.0f );
        //left
        glColor3f ( 1.0f,  1.0f,  0.0f );
        //glNormal3f(-0.96f,-0.29f, 0.0f );
        glVertex3f(-2.0f, -5.0f, -5.0f );
        glVertex3f(-2.0f, -5.0f,  5.0f );
        glVertex3f(-5.0f,  5.0f,  2.0f );
        glVertex3f(-5.0f,  5.0f, -2.0f );
    glEnd();

    glEnable(GL_CULL_FACE);
}

void SimpleTriangles::draw()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f );
    glVertex3f( 0.0f,  5.0f,  0.0f );
    glColor3f(1.0f, 0.0f, 0.0f );
    glVertex3f(-5.0f, -5.0f,  5.0f );
    glColor3f(0.0f, 1.0f, 0.0f );
    glVertex3f( 5.0f, -5.0f,  5.0f );

    glColor3f(0.0f, 0.0f, 1.0f );
    glVertex3f( 0.0f,  5.0f,  0.0f );
    glColor3f(0.0f, 1.0f, 0.0f );
    glVertex3f( 5.0f, -5.0f,  5.0f );
    glColor3f(0.0f, 1.0f, 1.0f );
    glVertex3f( 5.0f, -5.0f, -5.0f );

    glColor3f(0.0f, 0.0f, 1.0f );
    glVertex3f( 0.0f,  5.0f,  0.0f );
    glColor3f(0.0f, 1.0f, 1.0f );
    glVertex3f( 5.0f, -5.0f, -5.0f );
    glColor3f(1.0f, 1.0f, 0.0f );
    glVertex3f(-5.0f, -5.0f, -5.0f );

    glColor3f(0.0f, 0.0f, 1.0f );
    glVertex3f( 0.0f,  5.0f,  0.0f );
    glColor3f(1.0f, 1.0f, 0.0f );
    glVertex3f(-5.0f, -5.0f, -5.0f );
    glColor3f(1.0f, 0.0f, 0.0f );
    glVertex3f(-5.0f, -5.0f,  5.0f );
    glEnd();
}

void SimpleBox::draw()
{
    static GLfloat vertices[8][3] =
    {
        {-5.0f, -5.0f,  5.0f},     // vertex 0
        { 5.0f, -5.0f,  5.0f},     // vertex 1
        { 5.0f, -5.0f, -5.0f},     // vertex 2
        {-5.0f, -5.0f, -5.0f},     // vertex 3
        {-5.0f,  5.0f,  5.0f},     // vertex 4
        { 5.0f,  5.0f,  5.0f},     // vertex 5
        { 5.0f,  5.0f, -5.0f},     // vertex 6
        {-5.0f,  5.0f, -5.0f},     // vertex 7
    };

    static int faces[6*4] =
    {
        3, 0, 4, 7,		//face 0
        3, 2, 1, 0,		//face 1
        2, 3, 7, 6,		//face 2
        1, 2, 6, 5,		//face 3
        4, 5, 6, 7,		//face 4
        0, 1, 5, 4		//face 5
    };

    static GLfloat normals[6][3] =
    {
        { -1.0f,  0.0f,  0.0f},   // face 0
        {  0.0f, -1.0f,  0.0f},   // face 1
        {  0.0f,  0.0f, -1.0f},   // face 2
        {  1.0f,  0.0f,  0.0f},   // face 3
        {  0.0f,  1.0f,  0.0f},   // face 4
        {  0.0f,  0.0f,  1.0f},   // face 5
    };

    int numberOfFaces = 6;
    int verticesPerFace = 4;

    int n = 0;
    glColor3f(1.0f, 0.0f, 1.0f);
    for (int j=0; j<numberOfFaces; j++) {
        glBegin(GL_POLYGON);
        glNormal3fv(normals[j]);
        for (int k=0; k<verticesPerFace; k++) {
            glVertex3fv(vertices[ faces[n++] ]);
        }
        glEnd();
    }
}

void SimpleTeapot::draw()
{
    glColor3f(1.0f, 1.0f, 0.0f );
    glFrontFace(GL_CW);
    glutSolidTeapot(5);
    glFrontFace(GL_CCW);
}

SimpleBouncingBall::SimpleBouncingBall()
{
    timetick = 0;
    vel0  =  0.1;
    accel = -0.0005;
}

void SimpleBouncingBall::draw()
{
    float y = vel0*timetick + 0.5*accel*timetick*timetick;
    if (y < 0.0) {
        y = 0.0;
        timetick=0;
    }

    glColor3f(0.0f, 0.0f, 1.0f );
    glTranslatef(0.0f, y, 0.0f);
    glutSolidSphere(2.0,16,16);
    glutPostRedisplay();
}

void SimpleBouncingBall::tickTime(long int elapseTime)
{
    timetick += elapseTime;
};

void CGLab01VirtualWorld::draw()
{
	 glPushMatrix();
	    glTranslatef(-10.0f, 0.0f, 0.0f);
	    simplepolygon.draw();
	 glPopMatrix();

	 glPushMatrix();
	    glTranslatef( 0.0f, -3.0f, 0.0f);
	    glScalef( 1.0f, 0.2f, 1.0f);
	    simplebox.draw();
	 glPopMatrix();

	 glPushMatrix();
	    glTranslatef(  0.0f, 0.0f, -10.0f);
	    simpletriangles.draw();
	 glPopMatrix();

	 glPushMatrix();
	    glTranslatef(  0.0f, 0.0f,  10.0f);
	    simpleteapot.draw();
	 glPopMatrix();

	 glPushMatrix();
	    simplebouncingball.draw();
	 glPopMatrix();

	 glPushMatrix();
	    glTranslatef( 15.0f, -10.0f, 0.0f);
	    mymodelloader.draw();
	 glPopMatrix();

	deer->draw();
	elephant->draw();
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, -5.0f, -5.0f);
	glVertex3f(-4.0f, -5.0f,  5.0f);
	glVertex3f(0.0f, -5.0f,  7.0f);
	glVertex3f(4.0f, -5.0f,  5.0f);
	glVertex3f(4.0f, -5.0f, -5.0f);
	glVertex3f(0.0f, -5.0f, -7.0f);
	glEnd();

}
