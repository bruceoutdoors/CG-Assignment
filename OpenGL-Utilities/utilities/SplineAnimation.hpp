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

#include "Animatable.hpp"
#include "VecMatMath.hpp"
#include <vector>

class Transformable;

class SplineAnimation : public Animatable
{
public:
    SplineAnimation(std::vector<vec3> *spline, int moveInterval, bool hasRotation = true);
    virtual ~SplineAnimation();

    void updateFrame(int elapsedTime) override;

    void calculateAnglesAndAxis();
    void nextTransformation();
    Transformable *getTransformable() const;

private:
    std::vector<vec3> *spline, directions, rotationAxises;
    std::vector<float> angles;
    Transformable *t;
    int currentIdx;
    int moveInterval;
    int elapsedTimeFromLastMove;
    bool hasRotation;
};
