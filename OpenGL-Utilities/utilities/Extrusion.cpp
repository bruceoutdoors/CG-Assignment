/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "Extrusion.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
Extrusion::Extrusion(const std::vector<vec2> &points2d, int depth) :
    points2d(points2d), depth(depth)
{

}

void Extrusion::draw()
{
    glBegin(GL_POLYGON);
    for (auto &p : points2d) {
        glVertex3f(p[0], depth, p[1]);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (auto p = points2d.rbegin(); p != points2d.rend(); ++p) {
        glVertex3f((*p)[0], 0, (*p)[1]);
    }
    glEnd();

    glBegin(GL_QUADS);
    for (int i = 0; i < points2d.size(); i++) {
        glVertex3f(points2d[i][0], depth, points2d[i][1]);
        glVertex3f(points2d[i][0], 0, points2d[i][1]);

        int j = (i + 1) % points2d.size();
        glVertex3f(points2d[j][0], 0, points2d[j][1]);
        glVertex3f(points2d[j][0], depth, points2d[j][1]);
    }
    glEnd();
}

void Extrusion::setDepth(const int d)
{
    depth = d;
}

int Extrusion::getDepth() const
{
    return depth;
}
