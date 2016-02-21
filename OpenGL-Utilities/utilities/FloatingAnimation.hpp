#pragma once

#include "Animatable.hpp"
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
