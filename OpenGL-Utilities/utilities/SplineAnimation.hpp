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
