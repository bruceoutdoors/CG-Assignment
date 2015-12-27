#include "SelectMaster.hpp"
#include "Selectable.hpp"
#include <algorithm>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

SelectMaster::SelectMaster(Viewer& v, World &w) :
    viewer(v), world(w)
{

}


Selectable *SelectMaster::getSelect(int x, int y)
{
    static const GLuint BUFSIZE = 512;
    GLuint selectBuf[BUFSIZE];
    GLint hits;
    GLint viewport[4];

    glGetIntegerv (GL_VIEWPORT, viewport);

    glSelectBuffer (BUFSIZE, selectBuf);
    glRenderMode (GL_SELECT);

    glInitNames();
    glPushName(0);

    glPushMatrix();
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    gluPickMatrix ((GLdouble) x, (GLdouble) y,
                   5.0, 5.0, viewport);

    gluPerspective(viewer.fieldOfView,
                   viewer.aspectRatio,
                   viewer.zNear,
                   viewer.zFar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer.eyeX,    viewer.eyeY,    viewer.eyeZ,
              viewer.centerX, viewer.centerY, viewer.centerZ,
              viewer.upX,     viewer.upY,     viewer.upZ );

    glTranslatef(world.posX, world.posY, world.posZ);
    glRotatef(world.rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(world.rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(world.rotateZ, 0.0f, 0.0f, 1.0f);
    glScalef(world.scaleX, world.scaleY, world.scaleZ);

    for (auto &s : selectables) {
        glLoadName(s->getId());
        s->drawSelector();
    }

    glPopMatrix ();
    glFlush();

    hits = glRenderMode (GL_RENDER);

    restoreView();

    return processHits(hits, selectBuf);
}

void SelectMaster::addSelectable(Selectable* s)
{
    selectables.push_back(s);
}

void SelectMaster::removeSelectable(Selectable* s)
{
    auto rf = std::remove_if(selectables.begin(), selectables.end(),
                            [&](Selectable *x){ return s == x; });
    if (rf != selectables.end()) selectables.erase(rf);
}

void SelectMaster::clearSelectables()
{
    selectables.clear();
}

void SelectMaster::restoreView()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(viewer.fieldOfView,
                   viewer.aspectRatio,
                   viewer.zNear,
                   viewer.zFar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer.eyeX,   viewer.eyeY,   viewer.eyeZ,
              viewer.centerX,viewer.centerY,viewer.centerZ,
              viewer.upX,    viewer.upY,    viewer.upZ );
}


Selectable *SelectMaster::processHits(GLint hits, GLuint buffer[])
{
    unsigned int i, j;
    GLuint selected, names, *ptr;
    float closest = 99999;

    ptr = (GLuint *) buffer;
    for (i = 0; i < hits; i++) {   /*  for each hit  */
        float z, z1, z2;
        bool isClosest = false;

        names = *ptr;
//        printf (" number of names for hit = %d\n", names);
        ptr++;
        z1 = (float) *ptr/0x7fffffff;
//        printf("  z1 is %g;", z1);

        ptr++;
        z2 = (float) *ptr/0x7fffffff;
//        printf(" z2 is %g\n", z2);

        z = std::min(z1, z2);

        if (z < closest) {
            closest = z;
            isClosest = true;
        }

        ptr++;
//        printf ("   the name is ");
        for (j = 0; j < names; j++) {       /*  for each name */
//            printf ("%d ", *ptr);
            if (isClosest) selected = *ptr;
            ptr++;
        }
//        printf ("\n");
    }

    return Selectable::getSelectable(selected);
}
