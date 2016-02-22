/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "Lathe.hpp"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

Lathe::Lathe(std::vector<vec2> points, int segments)
{
    for (auto &p : points) {
        lathePoints.push_back(getCircle(p[0], segments, p[1]));
    }
}

Lathe::~Lathe()
{
    //dtor
}

void Lathe::draw()
{
    // draw points:
    /*
    for (auto &lp : lathePoints) {
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.0);
        for (auto it = lp.begin(); it != lp.end(); it++) {
            if (( it + 1) != lp.end()) {
                glVertex3f((*it)[0], (*it)[1], (*it)[2] );
                glVertex3f((*(it+1))[0], (*(it+1))[1], (*(it+1))[2] );
            }
        }
        glEnd();
    }
    */

    // connect with quads
    for (int i = 0; i < lathePoints.size() - 1; i++) {
        glBegin(GL_QUADS);
        for (int j = 0; j < lathePoints[i].size() - 1; j++) {
            glVertex3fv(&lathePoints[i+1][j][0]);
            glVertex3fv(&lathePoints[i+1][j+1][0]);
            glVertex3fv(&lathePoints[i][j+1][0]);
            glVertex3fv(&lathePoints[i][j][0]);
        }
        glEnd();
    }

    // draw top cap:
    glBegin(GL_TRIANGLES);
    for (int j = 0; j < lathePoints[0].size() - 1; j++) {
        glVertex3f(0, lathePoints[0][0][1], 0);
        glVertex3fv(&lathePoints[0][j][0]);
        glVertex3fv(&lathePoints[0][j+1][0]);
    }
    glEnd();

    // draw bottom cap:
    unsigned long fin = lathePoints.size() - 1;
    glBegin(GL_TRIANGLES);
    for (int j = 0; j < lathePoints[fin].size() - 1; j++) {
        glVertex3fv(&lathePoints[fin][j+1][0]);
        glVertex3fv(&lathePoints[fin][j][0]);
        glVertex3f(0, lathePoints[fin][0][1], 0);
    }
    glEnd();
}
