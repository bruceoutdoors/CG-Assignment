#include "SplineAnimation.hpp"
#include "Transformable.hpp"

SplineAnimation::SplineAnimation(std::vector<vec3> *spline, int moveInterval, bool hasRotation) :
    spline(spline), hasRotation(hasRotation),
    moveInterval(moveInterval), elapsedTimeFromLastMove(0),
    currentIdx(0)
{
    t = new Transformable(true);

    calculateAnglesAndAxis();
    nextTransformation();
}

void SplineAnimation::calculateAnglesAndAxis()
{
    directions = getDirections(*spline);
    angles.clear();
    rotationAxises.clear();

    static vec3 sourceDirection = {{ 0, 1, 0 }};

    for (const auto &d : directions) {
        float angleRad = acos(dot(unitVec(sourceDirection), unitVec(d)));
        vec3 axis = cross(sourceDirection, d);

        angles.push_back(angleRad * (180 / 3.1415926));
        rotationAxises.push_back(axis);
    }
}

SplineAnimation::~SplineAnimation()
{
    delete t;
}

void SplineAnimation::updateFrame(int elapsedTime)
{
    elapsedTimeFromLastMove += elapsedTime;

    if (elapsedTimeFromLastMove >= moveInterval) {
        nextTransformation();
        elapsedTimeFromLastMove = 0;
    }
}

void SplineAnimation::nextTransformation()
{
    currentIdx = currentIdx % angles.size();

    if (hasRotation) {
        t->setAxis(rotationAxises[currentIdx]);
        t->setAxisRotation(angles[currentIdx]);
    }

    t->setTranslate((*spline)[currentIdx]);

    currentIdx++;
}



Transformable *SplineAnimation::getTransformable() const
{
    return t;
}

