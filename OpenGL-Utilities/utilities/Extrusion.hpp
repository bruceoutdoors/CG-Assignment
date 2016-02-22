/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#pragma once

#include <vector>
#include "VecMatMath.hpp"
#include "Drawable.hpp"

class Extrusion : public Drawable
{
public:
    Extrusion(const std::vector<vec2> &points, int depth = 1);

    void draw() override;

    void setDepth(const int d);
    int getDepth() const;

private:
    const std::vector<vec2> &points2d;
    int depth;
};
