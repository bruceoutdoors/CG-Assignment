/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

/**
Replicate by path, Replicate.hpp

Co-Authors: Kah Loon, Bruce, IceBoy

@12/1/16

References: Lab Materials by Dr.Wong Ya Ping
            Loft Class by Hii Yong Lian
            OpenGL Utilities by Bruce

**/
#ifndef REPLICATE_HPP
#define REPLICATE_HPP

#include<vector>
#include "VecMatMath.hpp"
#include "Drawable.hpp"
#include "Mesh.hpp"
#include <cmath>
class Replicate
{
    public:
        Replicate();
        Replicate(const std::vector<vec3> &points, Drawable *picture);
        void draw();
    private:
        std::vector<vec3> pointsObj;
        std::vector<vec3> plottedPoints;
        Drawable *drawable;
        float radian;
        float degree;
        float axisValue;
        std::vector<vec3> axis;
};



#endif // REPLICATE_HPP
