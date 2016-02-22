#pragma once

#include "Animatable.hpp"
/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "VecMatMath.hpp"
#include "Transformable.hpp"
#include <vector>

class FloatingAnimation : public Animatable
{
public:
    FloatingAnimation(float speed, float strength);
    virtual ~FloatingAnimation();

    void updateFrame(int elapsedTime);

    Transformable *getTransformable();

private:
    Transformable t;
    int moveInterval;
    int elapsedTimeFromLastMove;
    double w;
    float speed;
    float strength;
};
